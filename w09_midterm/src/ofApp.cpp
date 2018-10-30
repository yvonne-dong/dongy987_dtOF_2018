#include "ofApp.h"
const int nPlanets = 30;
const int nMoons = 35;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60.f);
    camera.setNearClip(0.0);
    camera.setFarClip(10000);
    ofBackground(0);
    //set moons - movers
    for (int m=0; m<nMoons; m++)
    {
        moons.push_back(Moon());
    }
    //set planets - attractors
    for (int i=0; i<nPlanets; i++){
        Planet planet;
        planet.pos = center;
        planet.pos.x += ofRandom(-700, 700);
        planet.pos.y += ofRandom(-700, 700);
        planet.pos.z += ofRandom(-700, 700);
        planets.push_back(planet);
    }
    //draw boundary
    box = Box(glm::vec3(0,0,0), ofGetHeight()*2);
}

//--------------------------------------------------------------
void ofApp::update(){
    //set unlimited movement
    if (ofGetFrameNum() > 1){
        camera.setNearClip(0);
        camera.setFarClip(1000000);
    }
    //update planets
    for (int p=0; p<nPlanets; p++)
    {
        planets[p].update();
    }
    //apply force to moons
    for (int p=0; p<nPlanets; p++){
        for (int m=0; m<nMoons; m++){
            glm::vec3 force = planets[p].getForce(moons[m]);
            moons[m].applyForce(force);
        }
    }
    //update moons
    for (int m=0; m<nMoons; m++)
    {
        moons[m].bounceBack(box.getLeft(), box.getRight(), box.getTop(), box.getBottom(), box.getFront(), box.getBack());
        moons[m].update();
    }
    //update text
    for (int i=0; i<texts.size(); i++){
        texts[i].update();
    }
    //start counting the time to remove particle
    if (startFade){
        aliveTimeText++;
        if (aliveTimeText > 200){
            texts.clear();
            startFade = false;
            aliveTimeText = 0;
        }
    }
    //cout<<startFade<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    cout<<time<<endl;
    camera.begin();
    ofEnableDepthTest();
    camPos = camera.getPosition();
    
    if (time < 5) {
        ofDrawBitmapString("All That Is Solid Melts Into Air", glm::vec3(-120,0,0));
        ofDrawBitmapString("by Yvonne Dong", glm::vec3(-50,-20,0));
    } else {
        ofPushStyle();
        ofSetColor(255);
        ofNoFill();
        //draw planets
        for (int p=0; p<planets.size(); p++)
        {
            planets[p].draw();
        }
        //draw moons
        for (int m=0; m<nMoons; m++)
        {
            moons[m].draw();
        }
        //type words
        //ofPushMatrix();
        camera.transformGL();
        ofPushMatrix();
        ofTranslate(0,0,-100);
        for (int i=0; i<texts.size(); i++){
            texts[i].draw();
        }
        
        ofDrawBitmapString("arrow key + mouse: navigation", glm::vec3(-20,-40,0));
        ofDrawBitmapString("type in words then hit space to send out the message", glm::vec3(-35,-45,0));
        
        ofPopMatrix();
        camera.restoreTransformGL();
        //draw boundary
        //box.draw();
        ofPopStyle();
    }
    
    
    
    ofDisableDepthTest();
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP){
        camera.dolly(-moveIncrement);
    } else if (key == OF_KEY_LEFT){
        camera.truck(-moveIncrement);
    } else if (key == OF_KEY_RIGHT){
        camera.truck(moveIncrement);
    } else if (key == OF_KEY_DOWN){
        camera.dolly(moveIncrement);
    }
    //create new contour based on key
    if (key != ' ' && key != OF_KEY_UP && key != OF_KEY_LEFT
        && key != OF_KEY_RIGHT && key != OF_KEY_DOWN) {
        uint32_t letterEnter;
        letterEnter = key;
        addPos = posCount * 15;
        texts.push_back(Text(letterEnter, glm::vec3(startPos.x+addPos,0,0)) );
        posCount++;
    }
    //start add force and remove particle
    if (key == ' '){
        posCount = 0;
        for (int i=0; i<texts.size(); i++){
            texts[i].applyForce(glm::vec3(10,10,10));
        }
        startFade = true;
    }
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
