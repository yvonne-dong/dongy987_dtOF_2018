#include "hoop.hpp"

Hoop::Hoop(){
    pos     = glm::vec2( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()) );
    originPos = pos;
    mass    = 50;
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

Hoop::Hoop(glm::vec2 _pos, float _mass){
    pos     = _pos;
    originPos = pos;
    mass    = _mass;
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
}

void Hoop::applyForce(glm::vec2 force){
    // F = ma -> a = F/m
    acc += force/mass;
}

void Hoop::applyDampingForce(float strength){
    float length = glm::length(vel);
    
    if (length != 0.0){
        glm::vec2 direction = vel / length;
        applyForce( -direction * strength );
    }
    
}

void Hoop::applyElasticForce(){
    glm::vec2 elasticDir = (originPos-pos) * 0.02;
    applyForce(elasticDir);
}

//void Hoop::bounceEdge(){
//    if (pos.x < 0){
//        pos.x = 0;
//        vel.x *= -1;
//    }
//
//    if (pos.x > ofGetWidth()){
//        pos.x = ofGetWidth();
//        vel.x *= -1;
//    }
//
//    if (pos.y < 0){
//        pos.y = 0;
//        vel.y *= -1;
//    }
//
//    if (pos.y > ofGetHeight()){
//        pos.y = ofGetHeight();
//        vel.y *= -1;
//    }
//}

void Hoop::update(){
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Hoop::draw(){
    
    ofPushStyle();
    
    ofSetColor(255);
    ofNoFill();
    ofDrawCircle(pos, 0.1);
    
    ofPopStyle();
    
}
