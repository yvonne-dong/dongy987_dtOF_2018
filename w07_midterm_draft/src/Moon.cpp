

#include "Moon.hpp"

Moon::Moon(){
    pos     = glm::vec3( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    mass    = ofRandom(1,5);
    
    vel     = glm::vec3(0,0,0);
    acc     = glm::vec3(0,0,0);
}

Moon::Moon(glm::vec3 _pos, float _mass){
    pos     = _pos;
    mass    = _mass;
    
    vel     = glm::vec3(0,0,0);
    acc     = glm::vec3(0,0,0);
}

void Moon::applyForce(glm::vec3 force){
    acc += force/mass;
}

void Moon::applyDampingForce(float strength){
    float length = glm::length(vel);
    if (length != 0.0){
        glm::vec3 direction = vel / length;
        applyForce( -direction * strength );
    }
}

void Moon::bounceBack(float left, float right, float top, float bottom, float front, float back)
{
    
    if (pos.x < left + mass) {
        pos.x = left + mass;
        vel.x *= -1.;
    }
    
    if (pos.x > right - mass) {
        pos.x = right - mass;
        vel.x *= -1.;
    }
    
    if (pos.y > top - mass) {
        pos.y = top - mass;
        vel.y *= -1.;
    }
    
    if (pos.y < bottom + mass) {
        pos.y = bottom + mass;
        vel.y *= -1.;
    }
    
    if (pos.z < front + mass) {
        pos.z = front + mass;
        vel.z *= -1.;
    }
    
    if (pos.z > back - mass) {
        pos.z = back - mass;
        vel.z *= -1.;
    }
    
}

void Moon::update(){
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void Moon::draw(){
    
    ofPushStyle();
    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);
    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
    float percent    = ofMap(glm::length(vel), 0., 7., 0., 1., true);    // mix based on speed
    ofColor color   = cSlow.lerp(cFast, percent);    // "lerp" == interpolate
    
    ofSetColor(color);
    ofFill();
    ofDrawSphere(pos, mass * 2.);
    
    ofPopStyle();
    
}


