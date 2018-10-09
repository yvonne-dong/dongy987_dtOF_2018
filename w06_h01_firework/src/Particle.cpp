#include "Particle.hpp"

Particle::Particle(){
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    wordSetup();
    chosenWord = word[int(ofRandom(10))];
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass){
    pos = _pos;
    vel = _vel;
    mass = _mass;
    wordSetup();
    chosenWord = word[int(ofRandom(10))];
}

void Particle::wordSetup(){
    //"It's raining" by Guillaume Apollinaire
    word.push_back("its");
    word.push_back("raining");
    word.push_back("you");
    word.push_back("too");
    word.push_back("marvelous");
    word.push_back("encounters");
    word.push_back("of");
    word.push_back("my");
    word.push_back("life");
    word.push_back("oh");
    word.push_back("droplets");
}

void Particle::applyAcc(glm::vec2 force){
    acc += force / mass;
}

void Particle::applyDampingForce(float strength){
    float length = glm::length(vel);
    
    if (length != 0.0){
        glm::vec2 dir = vel / length;
        applyAcc( -dir * strength );
    }
}

void Particle::update(){
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw(){
    ofPushStyle();

    //transparent particle
    ofSetColor(255,0);
    ofNoFill();
    ofDrawCircle(pos, mass * 2.0);
    
    float blue = ofMap(mass, 1, 20, 0, 255);
    float a = ofMap(mass, 1, 20, 127, 255);
    ofEnableAlphaBlending();
    ofSetColor(blue, 243, 255, a);
    ofDrawBitmapString(chosenWord, pos);
    ofPopStyle();
}

void Particle::bounceEdge(){
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.x += ofRandom(-3,3);
        vel.y *= -1;
    }
}

