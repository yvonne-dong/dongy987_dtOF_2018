#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i = 0; i < 10; i++){
        float w = 100;
        float h = 70;
//--------------posX, posY, width, height, acceleration-----------
        float finnX = ofRandom(ofGetWidth());
        float finnY = ofRandom(0, ofGetHeight()*0.5);
        addFinn[i].setup(finnX, finnY, w, h, glm::vec2(ofRandom(-5, 5), 0));
        
        addFinn[i].color.r = ofRandom(100, 255);
        addFinn[i].color.g = ofRandom(100, 255);
        addFinn[i].color.b = ofMap(i, 0, 20, 0 ,255);
        
        gravity = glm::vec2(0,i*0.1);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < 10; i++){
        addFinn[i].update();
        addFinn[i].bounce();
        addFinn[i].addForce(gravity);
        addFinn[i].damping();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    for(int i = 0; i < 10; i++){
        addFinn[i].draw();
        ofSetColor(255, 100, 100);
        ofFill();
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
    for(int i = 0; i < 10; i++){
        addFinn[i].addForce(glm::vec2(5,0));
    }
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
