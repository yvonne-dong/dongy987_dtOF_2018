//
//  TextParticle.cpp
//  fontShapesExample
//
//  Created by Yanwen Dong on 2018/10/27.
//

#include "TextParticle.hpp"

TextParticle::TextParticle(){
    pos = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    vel = glm::vec3(0,0,0);
    acc = glm::vec3(0,0,0);
    mass = ofRandom(1,5);
    bornTime = ofGetElapsedTimef();
    fade = false;
}

TextParticle::TextParticle(glm::vec3 _pos){
    
    pos = _pos;
    vel = glm::vec3(0,0,0);
    acc = glm::vec3(0,0,0);
    mass = ofRandom(1,5);
    bornTime = ofGetElapsedTimef();
    fade = false;
}

//force that dissolve the text shape
void TextParticle::applyForce(glm::vec3 force){
    acc += force/mass;
    fade = true;
}

void TextParticle::bounceBack(float left, float right, float top, float bottom, float front, float back)
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

void TextParticle::update(){
    vel += acc;
    pos += vel;
    acc *= 0;
}

void TextParticle::draw(){
    ofPushStyle();
    //fade: alpha decrease
    if (fade) {
        float hue = ofMap(mass, 1, 5, 0, 255);
        float sat = 255;
        float brt = 255;
        float aliveTime = ofGetElapsedTimef() - bornTime;
        float alpha = ofMap(aliveTime, 0, 5, 255, 0, true);
        
        ofColor color = ofColor::fromHsb(hue,sat,brt,alpha);
        ofSetColor(color);
        //ofSetColor(255, 255, 255, alpha);
    } else {
        ofSetColor(255);
    }
    ofDrawBox(pos.x,pos.y,pos.z,
              1,3,1);
    ofPopStyle();
}


