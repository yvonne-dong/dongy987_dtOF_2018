#include "ofApp.h"
const float FLOAT_MIN = std::numeric_limits<float>::min();
const float FLOAT_MAX = std::numeric_limits<float>::max();

const int nFace = 6;

const int nSounds = 6; //length of sound vector - all sounds in the folder
const int nValAnalog = 6; //A0 - A5 6 tracks
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(190,106,74);
    cam.setup(640, 480);
    
    ard.connect("/dev/cu.usbmodem1411", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = false;
    
    for (int i = 0; i < nSounds; i ++){
        ofSoundPlayer sound;
        int nameNum = i+1;
        sound.load(ofToString(nameNum) + ".mp3");
        sounds.push_back(sound);
    }
    
    for (int j = 0; j < nValAnalog; j ++) {
        string analogValue = "value";
        string resistanceVal = "rVal";
        float floatValResistance = 0.;
        float wobblySpeed = 1;
        bool bUpdateFace = false;
        valAnalog.push_back(analogValue);
        valResistance.push_back(resistanceVal);
        fValResistance.push_back(floatValResistance);
        updateFace.push_back(bUpdateFace);
        updateWobbly.push_back(wobblySpeed);
    }
    
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset( ObjectFinder::Preset::Fast );
    finder.getTracker().setPersistence(60);
    
    w = ofGetWidth();
    h = ofGetHeight();
    screenCenter = glm::vec2(cam.getWidth()/2,cam.getHeight()/2);
    
   
    for (int j = 0; j < nFace; j ++) {
        ofPath path = setFace(glm::vec2(0,0),100);
        ofMesh face = path.getTessellation();
        ofImage image;
        Eyes eye = Eyes(glm::vec2(150+j*200,h/2-20), glm::vec2(150+j*200,h/2-20),15, 40);
        
        auto& meshVertices = face.getVertices();
        auto& meshTexCoords = face.getTexCoords();
        
        float left      = FLOAT_MAX;
        float top       = FLOAT_MAX;
        float right     = FLOAT_MIN;
        float bottom    = FLOAT_MIN;
        
        for (int i = 0; i < meshVertices.size(); i ++)
        {
            glm::vec3 vertex = meshVertices[i];
            left    = min(left, vertex.x);
            top     = min(top, vertex.y);
            right   = max(right, vertex.x);
            bottom  = max(bottom, vertex.y);
        }
        bound = ofRectangle(glm::vec2(left, top), glm::vec2(right, bottom));
        
        image.load(ofToString(j+1)+".jpg");
        
        float textureW = image.getWidth();
        float textureH = image.getHeight();
        
        for (int i = 0; i < meshVertices.size(); i ++)
        {
            glm::vec3 vertex = meshVertices[i];
            float x = ofMap(vertex.x, left, right, 0, textureW);
            float y = ofMap(vertex.y, top, bottom, 0, textureH);
            
            face.addTexCoord( glm::vec2(x,y) );
        }
        
//        updateFace.push_back(j+1); //the num to call
        allEyes.push_back(eye);
        faces.push_back(face);
        textureImg.push_back(image);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    updateArduino();
    float time = ofGetElapsedTimef()* .5;
    cam.update();
    if (cam.isFrameNew()){
        mirrorCam.setFromPixels( cam.getPixels() );
        mirrorCam.mirror(false, true);
        finder.update(mirrorCam);
    }
    
    
    for (int j = 0; j < faces.size(); j++) {
//    for (int j = 0; j < updateFace.size(); j++) {
        if (updateFace[j] == true) {
            for (int i = 0; i < faces[j].getVertices().size(); i ++)
            {
                glm::vec3& vertex = faces[j].getVertices()[i];
                float length = glm::length(vertex);
                glm::vec3 norm = vertex / length;
                float noise     = ofSignedNoise(glm::vec3(time * 2) + norm * 2);
                vertex          = norm * (100 + noise * 10 * updateWobbly[j] );
            }
            allEyes[j].update(direction, 50+sin(time*5)*30);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = true;
    for (int i = 0; i < nValAnalog; i ++) {
        ard.sendAnalogPinReporting(i, ARD_ANALOG);
    }
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    //update the arduino, get any data or messages.
    ard.update();
}
//--------------------------------------------------------------
//calculate resistance change for each track
void ofApp::calculateResistance(int _pinNum){
    int raw = 0;
    
    raw = ard.getAnalog(_pinNum);
    fValResistance[_pinNum] = raw;
    valResistance[_pinNum] = ofToString(raw);
}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    if (pinNum == 0) {
        valAnalog[0] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 1) {
        valAnalog[1] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 2) {
        valAnalog[2] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 3) {
        valAnalog[3] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 4) {
        valAnalog[4] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 5) {
        valAnalog[5] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    mirrorCam.draw(w/2-cam.getWidth()/2,h/2-cam.getHeight()/2);
    for(int i = 0; i < faces.size(); i++) {
        ofPushMatrix();
        ofTranslate(150+i*200, ofGetHeight()*0.5);
        textureImg[i].bind();
        faces[i].draw();
        textureImg[i].unbind();
        ofPopMatrix();
    }
    
//    updateFace[j] = true;
//    updateWobbly[j] = 1.0;
    
    if (!bSetupArduino){
        ofDrawBitmapString("arduino not ready...\n", 50, 600);
        for (int j = 0; j < faces.size(); j ++) {
            allEyes[j].sleepMode();
            
        }
    } else {
        for (int i = 0; i < valAnalog.size(); i ++) {
            ofDrawBitmapString("track "+ ofToString(i)+ ": "+valAnalog[i], 50, 600+i*20);
//            ofDrawBitmapString("R2: "+ valResistance[i], 515, 60+i*40);
        }
        
        for (int j = 0; j < fValResistance.size(); j ++) {
            if((fValResistance[j] > 300 && fValResistance[j] < 600) && !sounds[j].isPlaying()) {
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(0.5f);
//                allEyes[j].draw();
                updateFace[j] = true;
                updateWobbly[j] = 0.5;
            } else if((fValResistance[j] > 600 && fValResistance[j] < 780) && !sounds[j].isPlaying()){
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(1.0f);
//                allEyes[j].draw();
                updateFace[j] = true;
                updateWobbly[j] = 1.0;
            } else if ((fValResistance[j] > 780 && fValResistance[j] < 880)&& !sounds[j].isPlaying()) {
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(1.5f);
//                allEyes[j].draw();
                updateFace[j] = true;
                updateWobbly[j] = 1.5;
            } else if (fValResistance[j] > 880 || fValResistance[j] == 0) {
                stopSound(j);
                updateFace[j] = false;
                updateWobbly[j] = 1.0;
//                for (int k = 0; k < updateFace.size(); k ++) {
//                    updateFace[k] = false;
//                }
            }
        }
    }
    
    
    
    for (int i = 0; i < finder.size(); i++) {
        //detect face
        ofRectangle tempFace = finder.getObjectSmoothed(i);
        faceCenter = glm::vec2(tempFace.getCenter().x, tempFace.getCenter().y);
        float length = glm::length(faceCenter - screenCenter);
        direction = (faceCenter - screenCenter)/length;
    }
    
    for (int j = 0; j < faces.size(); j ++) {
        if (updateFace[j] == true) {
            allEyes[j].draw();
        } else if (updateFace[j] == false) {
            allEyes[j].sleepMode();
        }
    }
    
    cout<<ofToString(updateFace)<<endl;
    
    
    
//    ofPushStyle();
//    ofSetColor(255,0,255);
//    ofNoFill();
//    ofDrawRectangle( bound );
////    ofSetColor(255);
////    faceA0.drawWireframe();
//    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::stopSound(int _soundNum){
    if (sounds[_soundNum].isPlaying()) {
        sounds[_soundNum].stop();
    }
}
//--------------------------------------------------------------
ofPath ofApp::setFace(glm::vec2 centerPos, int radius){
    ofPath facePath;
    for (float i = 0.; i < TWO_PI; i += .05) {
        glm::vec2 pos;
        pos.x = centerPos.x + (cos(i) * radius);
        pos.y = centerPos.y + (sin(i) * radius);
        
        glm::vec2 norm = pos/radius;
        if (i == 0) {
            facePath.moveTo(pos);
        }
        else {
            facePath.curveTo(pos);
        }
    }
    facePath.close();
    return facePath;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    updateFace.push_back(key-1);
    //    updateFace[key] = true;
    //    updateWobbly[key] = 1.0;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
