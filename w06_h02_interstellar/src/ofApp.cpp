#include "ofApp.h"

const int nAttractors    = 15;
const int nMovers        = 20;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60.);
    
    glm::vec2 center  = ofGetWindowSize() * .5;               // center screen
    
    float maxAngle = TWO_PI;
    for (float theta = 0.; theta < maxAngle; theta += .05){
        float radius = 300;
        glm::vec2 pos;
        pos.x = center.x + (cos(theta) * radius);
        pos.y = center.y + (sin(theta) * radius);
        
        Hoop hoopCircle = Hoop(pos, 1.);
        hoop.push_back(hoopCircle);
    }
    
    for (int m=0; m<nMovers; m++)
    {
        moveStars.push_back(MoveStar());
    }
    
    for (int a=0; a<nAttractors; a++){
        AttractStar attractStar;
        attractStar.pos   = center;
        attractStar.pos.x += ofRandom(-150., 150.);
        attractStar.pos.y += ofRandom(-150., 150.);
        attractStars.push_back(attractStar);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
    for (int a=0; a<nAttractors; a++){
        attractStars[a].update();
    }
    
    for (int a=0; a<nAttractors; a++){
        for (int m=0; m<nMovers; m++){
            // calculate force
            glm::vec2 force = attractStars[a].getForce(moveStars[m]);
            // apply force
            moveStars[m].applyForce(force);
        }
    }
    
    // update movers
    for (int m=0; m<nMovers; m++){
        
        for (int i=0; i<hoop.size(); i++){
            
            glm::vec2 diff = moveStars[m].pos - hoop[i].pos;
            float dist = glm::length(diff);
            glm::vec2 mouseDiff = mousePos - hoop[i].pos;
            float mouseDist = glm::length(mouseDiff);
            
            if (dist < 150. && dist != 0.){
                glm::vec2 diffNorm  = diff / dist;
                glm::vec2 repulsion = diffNorm * -.6;
                hoop[i].applyForce(repulsion);
            }
            
            if (mouseDist < 100. && mouseDist != 0.){
                glm::vec2 mouseDiffNorm  = mouseDiff / mouseDist;
                glm::vec2 mouseRepulsion = mouseDiffNorm * -.5;
                hoop[i].applyForce(mouseRepulsion);
            }
            
            hoop[i].applyElasticForce();
            hoop[i].applyDampingForce(0.05);
            hoop[i].update();
        }
        
        moveStars[m].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 100);
    ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
    
    ofBackground(0);
    //ofBackgroundGradient(ofColor::lightSkyBlue, ofColor::black);
    
    ofPushStyle();
    ofSetColor(255);
    ofSetLineWidth(2);
    for (int i=0; i<hoop.size(); i++){
        if (i < hoop.size()-1){
            ofDrawLine(hoop[i].pos, hoop[i+1].pos);
        }
        hoop[i].draw();
    }
    ofDrawLine(hoop[0].pos, hoop[TWO_PI/.05].pos);
    ofPopStyle();
    
    for (int a=0; a<nAttractors; a++){
        attractStars[a].draw();
    }
    
    for (int m=0; m<nMovers; m++)
    {
        moveStars[m].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
//    if (key == ' ')
//    {
//        bSpin = !bSpin;    // toggle wind
//    }
    
}
