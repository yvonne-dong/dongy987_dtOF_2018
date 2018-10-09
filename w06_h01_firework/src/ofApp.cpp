#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(30.);
    
   
    //glm::vec2 pos1 = glm::vec2(ofGetWidth() * 0.5-100, 10);
    //ParticleSystem particleSystem1 = ParticleSystem(pos1);
//
//    glm::vec2 pos2 = glm::vec2(ofGetWidth() * 0.5+100, 10);
//    ParticleSystem particleSystem2 = ParticleSystem(pos2);
//
   // particleSystems.push_back(particleSystem1);
//    particleSystems.push_back(particleSystem2)
    
    gravity = glm::vec2(0, .15);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
//
    for (int i=0; i<particleSystems.size(); i++){
        glm::vec2 repulsion;
        glm::vec2 repDir = mousePos - particleSystems[i].pos;
        float distance = glm::length(repDir);
        if (distance > 0) {
            glm::vec2 normDir = repDir / distance;
            if (distance < 100) {
                repulsion = -normDir;
            }
        }
        
        particleSystems[i].applyMouseForce(repulsion);
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapStringHighlight("It's raining - Guillaume Apollinaire", glm::vec2(ofGetWidth()*0.5-140,40), ofColor::lightBlue, ofColor::black);
    ofDrawBitmapStringHighlight("press mouse for rain", glm::vec2(ofGetWidth()*0.5-90,60), ofColor::lightBlue, ofColor::black);
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' '){
         particleSystems.push_back( ParticleSystem(glm::vec2(pos1.x + 100 * count, pos1.y)) );
    }
    count ++;
    cout<<count<<endl;
}
