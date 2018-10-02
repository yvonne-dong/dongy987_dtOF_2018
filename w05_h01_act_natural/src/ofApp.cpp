#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofNoFill();
    //ofSetLineWidth(3);
//    int birdNum = 50;
    
    for (int i=0; i<birdNum; i++){
     
        Bird bird;
        
        bird.pos   = glm::vec2(0,0);
        bird.speed = ofMap(i, 0, birdNum, .008, .04);
        bird.size  = ofMap(i, 0, birdNum, 8, 3);
        
        float g = ofMap(i, 0, birdNum, 50, 200);
//        float hue   = ofMap(i, 0, birdNum, 50, 100);     // blue to red
        bird.color = ofColor(255, g, 0);        // hue, saturation, brightness
        
        birds.push_back(bird);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = pressedPos;
    
    for (int i=0; i < birdNum; i++){
        glm::vec2 noise;
        float frequency     = 10. * birds[i].speed;
        //float amplitude     = 400.;
        float amplitude     = 100.;
        
//        noise.x = ofSignedNoise((ofGetElapsedTimef()+50) * frequency) * amplitude;
        noise.x = sin(ofGetElapsedTimef()+frequency);
//        noise.y = ofSignedNoise((ofGetElapsedTimef()+100) * frequency) * amplitude;
        noise.y = cos(ofGetElapsedTimef()+frequency);
        
        glm::vec2 noisyTarget = mousePos + noise;
        
        glm::vec2 mousePos = pressedPos;
        birds[i].update(noisyTarget);
//        for (int j = 0; j < i; j++){
//            birds[i].addRepulsion(birds[j], 5, 0.4);
//        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i < birdNum; i++){
        birds[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    pressedPos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    ofSetColor(255);
    //ofFill();
    ofDrawCircle(0, 0, 20);
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
