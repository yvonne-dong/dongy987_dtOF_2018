
#include "Eyes.hpp"

Eyes::Eyes(){
    eyePos      = glm::vec2(0,0);
    eyeCenter   = glm::vec2(0,0);
    eyeSize     = 20;
    mouthSize   = 40;
}

Eyes::Eyes(glm::vec2 _eyePos, glm::vec2 _screenCenter, float _eyeSize, float _mouthSize){
    eyePos      = _eyePos;
    eyeCenter   = _screenCenter;
    eyeSize     = _eyeSize;
    mouthSize   = _mouthSize;
}

void Eyes::update(glm::vec2 dir, float mouthMovement){
    float dist = glm::length(eyePos - eyeCenter);
    eyePos = eyeCenter + dir * eyeSize;
    mouthSize = mouthMovement;
}

void Eyes::draw(){
    ofPushStyle();
    ofSetColor(192,150,123);
    ofSetLineWidth(3);
    ofNoFill();
    ofDrawCircle(eyeCenter.x-eyeSize*2, eyeCenter.y, eyeSize*2);
    ofDrawCircle(eyeCenter.x+eyeSize*2, eyeCenter.y, eyeSize*2);
    
    ofDrawCurve(eyeCenter.x-30,eyeCenter.y+eyeSize+5,
                eyeCenter.x, eyeCenter.y+eyeSize, eyeCenter.x, eyeCenter.y+eyeSize*2, eyeCenter.x-30, eyeCenter.y+eyeSize+5);
    ofPopStyle();
    
    ofPushStyle();
    ofSetColor(192,150,123);
    //radius: 20
    ofDrawCircle(eyePos.x-eyeSize*2, eyePos.y, eyeSize);
    ofDrawCircle(eyePos.x+eyeSize*2, eyePos.y, eyeSize);
    ofDrawEllipse(eyeCenter.x, eyeCenter.y+eyeSize*4, mouthSize, mouthSize*0.5);
    ofPopStyle();
}

void Eyes::sleepMode(){
    ofPushStyle();
    ofSetColor(192,150,123);
    ofSetLineWidth(3);
    ofNoFill();
    //closed eyes
    ofDrawCurve(eyePos.x-eyeSize*3, eyePos.y-80,
                eyePos.x-eyeSize*4, eyePos.y,
                eyePos.x-eyeSize, eyePos.y,
                eyePos.x-eyeSize*2, eyePos.y-80);
    ofDrawCurve(eyePos.x+eyeSize*3, eyePos.y-80,
                eyePos.x+eyeSize*4, eyePos.y,
                eyePos.x+eyeSize, eyePos.y,
                eyePos.x+eyeSize*2, eyePos.y-80);
    //mouth
    ofDrawCurve(eyePos.x-eyeSize*3+60, eyeCenter.y-eyeSize*5,
        eyePos.x-eyeSize*3+20,eyeCenter.y+eyeSize*3,
        eyePos.x+eyeSize*3-20,eyeCenter.y+eyeSize*3,
        eyePos.x+eyeSize*3-60, eyeCenter.y-eyeSize*5);
    //nose
    ofDrawCurve(eyeCenter.x-30,eyeCenter.y+eyeSize+5,
                eyeCenter.x, eyeCenter.y+eyeSize, eyeCenter.x, eyeCenter.y+eyeSize*2, eyeCenter.x-30, eyeCenter.y+eyeSize+5);
    
    ofPopStyle();
}
