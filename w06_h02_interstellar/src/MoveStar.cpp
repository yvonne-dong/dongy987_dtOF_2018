
#include "MoveStar.hpp"

MoveStar::MoveStar(){
    pos     = glm::vec2( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()) );
    mass    = ofRandom(1,5);
    
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

MoveStar::MoveStar(glm::vec2 _pos, float _mass){
    pos     = _pos;
    mass    = _mass;
    
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

void MoveStar::applyForce(glm::vec2 force){
    acc += force/mass;
}

void MoveStar::applyDampingForce(float strength){
    float length = glm::length(vel);
    if (length != 0.0){
        glm::vec2 direction = vel / length;
        applyForce( -direction * strength );
    }
    
}

void MoveStar::bounceWindowEdges() {
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void MoveStar::update(){
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void MoveStar::draw(){
    
    ofPushStyle();
    ofNoFill();
    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);
    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
    float percent    = ofMap(glm::length(vel), 0., 7., 0., 1., true);    // mix based on speed
    ofColor color   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(color);
    
//    ofDrawCircle(pos, mass * 2.);
//    ofSetLineWidth(10);
    for (int i = 1; i < 5; i ++) {
        ofDrawCircle(pos, mass * i * 1.5);
    }
   
    ofPopStyle();
    
}
