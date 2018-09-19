#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    for (int i = 0; i < 20; i ++){
        //float w = ofRandom(20, 50);
        float w = 100;
        float h = 70;
        float aStart = 0;
        face[i].setup(ofGetWidth()*0.5+i*2, ofGetHeight()*0.5, w+i*0.5, h+i*0.5, aStart+i*50);
        face[i].lerp= 0.03+i*0.005;
        

        //float hue = ofMap(speed, 5, 20, 100, 200);
        face[i].color.r = ofRandom(100, 255);
        face[i].color.g = ofRandom(100, 255);
        face[i].color.b = ofMap(i, 0, 20, 0 ,255);
        face[i].color.a = ofMap(i, 0, 20, 0 ,150);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 20; i ++){
        face[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 20; i ++){
        face[i].draw();
        
        
        ofSetColor(255, 100, 100);
        ofFill();
//        ofDrawCircle(i+100,ofGetHeight()*0.5,
//                     50+sin(time)*50,50+sin(time)*50);
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
