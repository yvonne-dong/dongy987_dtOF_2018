#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofNoFill();
    
    for (int i=0; i<birdNum; i++){
     
        Bird bird;
        
        bird.pos   = glm::vec2(0,0);
        bird.speed = ofMap(i, 0, birdNum, .008, .04);
        bird.size  = ofMap(i, 0, birdNum, 8, 3);
        
        float g = ofMap(i, 0, birdNum, 50, 200);
        bird.color = ofColor(255, g, 0);
        birds.push_back(bird);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = pressedPos;
    
    for (int i=0; i < birdNum; i++){
        glm::vec2 movement;
        float frequency     = 10. * birds[i].speed;
        float amplitude     = 100.;
        
        movement.x = sin(ofGetElapsedTimef()+frequency);
        movement.y = cos(ofGetElapsedTimef()+frequency);
        
        glm::vec2 moveToPos = mousePos + movement;
        
        glm::vec2 mousePos = pressedPos;
        birds[i].update(moveToPos);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i < birdNum; i++){
        birds[i].draw();
    }
    
    
    if (mouseP == true){
        for (int i = 0; i < 5; i ++) {
            ofSetColor(ofMap(i, 0, 5, 255, 100), 255, 255, 100);
            ofDrawCircle(foodPos,foodR*i*0.3);
            foodR += 0.09;
        }
    }
    if (foodR > 80){
        foodR = 0;
        mouseP = false;
    }
    
    ofSetColor(255);
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
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouseP = true;
    foodPos = glm::vec2(ofGetMouseX(), ofGetMouseY());
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
