#include "Wind.h"

// --------------------------------------------------------
void Finn::setup(float posX, float posY, float width, float height, glm::vec2 acceleration){
    
    pos = glm::vec2(posX, posY);
    w = width;
    h = height;
    mouthH = 20;
    vel = glm::vec2(0, 0.1);
    
    color = ofColor(255);
    acc = acceleration;
}

// --------------------------------------------------------
void Finn::update(){
    
    
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    vel += acc;
    pos += vel;    
    acc *= 0;
    
}
// --------------------------------------------------------
void Finn::draw(){
    faceC = ofColor(255, 226, 239);
    lEyeP = glm::vec2(pos.x+w/2-20, pos.y+h/2-8);
    rEyeP = glm::vec2(pos.x+w/2+20, pos.y+h/2-8);
    mouthX = pos.x+w/2;
    mouthY = pos.y+h/2+15;
//--------------------------outerside-----------------------------
    ofSetColor(color);
    ofFill();
    ofDrawRectangle(pos.x,pos.y,w,h);
    ofDrawRectangle(pos.x,pos.y-10,20,h);
    ofDrawRectangle(pos.x+w-20,pos.y-10,20,h);
//-----------------------face-------------------------------------
    ofSetColor(faceC);
    ofFill();
    ofRectangle myFace;
    myFace.x = pos.x+10;
    myFace.y = pos.y+10;
    myFace.width = w-20;
    myFace.height = h-20;
    ofDrawRectRounded( myFace, 15 );
    ofSetColor(255, 0, 0);
//--------------------------mouth---------------------------------
    ofSetColor(255, 100, 100);
    ofFill();
    float dist = glm::distance(mouse,pos);
    mouthH = ofMap(dist, 0, 300, 5, 20);
    ofDrawEllipse(mouthX,mouthY,mouthH,mouthH);
//----------------------------eyes--------------------------------
    ofSetColor(0);
    ofFill();
    ofDrawCircle(lEyeP.x,lEyeP.y,5,5);
    ofDrawCircle(rEyeP.x,rEyeP.y,5,5);
    ofSetColor(255);
}
//----------------------------force------------------------------
void Finn::addForce(glm::vec2 force){
    acc += force;       // add acceleration force
}
//----------------------------bounce------------------------------
void Finn::bounce(){
    if(pos.x - w/2 > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    else if (pos.x + w/2 < 0){
        pos.x = 0;
        vel.x *= -1;
    }
    if(pos.y - h/2 > ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
        else if (pos.y + h/2 < 0){
            pos.y = 0;
            vel.y *= -1;
        }
}
//----------------------------bounce------------------------------
void Finn::damping(){
    
    vel *= 0.99;
    
}

