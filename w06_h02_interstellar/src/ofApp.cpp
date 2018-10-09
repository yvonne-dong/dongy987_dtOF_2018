#include "ofApp.h"

const int nAttractors    = 15;
const int nMovers        = 20;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60.);
    
    glm::vec2 center  = ofGetWindowSize() * .5;
   
    float maxAngle = TWO_PI;
    for (float theta = 0.; theta < maxAngle; theta += .05){
        float mainRadius = 300;
        glm::vec2 pos;
        pos.x = center.x + (cos(theta) * mainRadius);
        pos.y = center.y + (sin(theta) * mainRadius);
        
        Hoop mainHoopCircle = Hoop(pos, 1.);
        hoop.push_back(mainHoopCircle);
    }
    
    //other one
    for (int i = 1; i < 10; i ++) {
        glm::vec2 randomPos = glm::vec2(ofGetWidth()*.5+ofRandom(-200,200),ofGetHeight()*.5+ofRandom(-200,200));
        for (float alpha = 0.; alpha < maxAngle; alpha += .05){
            float radius = 80;
            glm::vec2 pos;
            pos.x = randomPos.x + (cos(alpha) * radius);
            pos.y = randomPos.y + (sin(alpha) * radius);
            
            Hoop hoopCircle = Hoop(pos, 1.);
            hoop.push_back(hoopCircle);
        }
    }
    
    //moving stars
    for (int m=0; m<nMovers; m++)
    {
        moveStars.push_back(MoveStar());
    }
    
    //attractor stars
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
    
    //update attractor
    for (int a=0; a<nAttractors; a++){
        attractStars[a].update();
    }
    
    //update force for moving stars
    for (int a=0; a<nAttractors; a++){
        for (int m=0; m<nMovers; m++){
            glm::vec2 force = attractStars[a].getForce(moveStars[m]);
            moveStars[m].applyForce(force);
        }
    }
    
    // update movers
    for (int m=0; m<nMovers; m++){
        
        for (int i=0; i< hoop.size(); i++){
            
            glm::vec2 diff = moveStars[m].pos - hoop[i].pos;
            float dist = glm::length(diff);
            glm::vec2 mouseDiff = mousePos - hoop[i].pos;
            float mouseDist = glm::length(mouseDiff);
            
            if (dist < 150. && dist != 0.){
                glm::vec2 diffNorm  = diff / dist;
                glm::vec2 repulsion = diffNorm * -.6;
                hoop[i].applyForce(repulsion);
            }
            
            if (mouseDist < 50. && mouseDist != 0.){
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
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    ofSetColor(0, 0, 0, 100);
    ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
    
    ofBackground(0);
    //ofBackgroundGradient(ofColor::lightSkyBlue, ofColor::black);
    
    ofPushStyle();
    ofSetColor(255);
    ofSetLineWidth(2);
    
    //main circle
    for (int i=0; i< mainHoopSize; i++){
        if (i < mainHoopSize-1){
            ofDrawLine(hoop[i].pos, hoop[i+1].pos);
        }
        hoop[i].draw();
    }
    ofDrawLine(hoop[0].pos, hoop[mainHoopSize].pos);
    
    
    //other circles
    for (int i = 1; i < 3; i ++) {
        for (int j= int(mainHoopSize*i+1); j< mainHoopSize * (i+1); j++){
            if (j < mainHoopSize * (i+1)-1){
                ofDrawLine(hoop[j].pos, hoop[j+1].pos);
            }
            hoop[j].draw();
        }
        ofDrawLine(hoop[mainHoopSize*i+1].pos, hoop[mainHoopSize*(i+1)].pos);
    }
    ofPopStyle();
    
    
    for (int a=0; a<nAttractors; a++){
        attractStars[a].draw();
    }
    
    for (int m=0; m<nMovers; m++)
    {
        moveStars[m].draw();
    }
}
