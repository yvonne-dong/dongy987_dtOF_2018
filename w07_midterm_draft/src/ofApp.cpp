#include "ofApp.h"
const int nPlanets = 20;
const int nMoons = 15;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60.f);
    ofBackground(0);
    camera.setNearClip(0.0);
    camera.setFarClip(10000);
    
    for (int m=0; m<nMoons; m++)
    {
        moons.push_back(Moon());
    }
    
    for (int i=0; i<nPlanets; i++){
        Planet planet;
        planet.pos = center;
        planet.pos.x += ofRandom(-300, 300);
        planet.pos.y += ofRandom(-300, 300);
        planet.pos.z += ofRandom(-300, 300);
        planets.push_back(planet);
    }
    
    box = Box(glm::vec3(0,0,0), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetFrameNum() > 1){
        camera.setNearClip(0);
        camera.setFarClip(1000000);
    }

    
    for (int p=0; p<nPlanets; p++)
    {
        planets[p].update();
    }
    
    for (int p=0; p<nPlanets; p++){
        for (int m=0; m<nMoons; m++){
            glm::vec3 force = planets[p].getForce(moons[m]);
            moons[m].applyForce(force);
        }
    }
    
    for (int m=0; m<nMoons; m++)
    {
        moons[m].bounceBack(box.getLeft(), box.getRight(), box.getTop(), box.getBottom(), box.getFront(), box.getBack());
        moons[m].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    ofEnableDepthTest();
    ofNoFill();
    for (int p=0; p<planets.size(); p++)
    {
        planets[p].draw();
    }
    
    for (int m=0; m<nMoons; m++)
    {
        moons[m].draw();
    }
    
    ofNoFill();
    box.draw();
    
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
