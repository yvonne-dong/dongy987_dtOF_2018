
#include "AttractStar.hpp"

AttractStar::AttractStar(){
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    mass = ofRandom(5.,30.);
    amplitude = 5;
}

AttractStar::AttractStar(glm::vec2 _pos, float _mass){
    pos = _pos;
    mass = ofClamp(_mass, 5., 30.); // keep mass between 5 and 30
    amplitude = 50;
}

glm::vec2 AttractStar::getForce(MoveStar moveStar){
    glm::vec2 force = glm::vec2(0,0);
    glm::vec2 dir    = pos - moveStar.pos;
    float distance    = glm::length(dir);

    if (distance > 0) {
        // gravity magnitude = (G * mass1 * mass2) / (distance * distance)
        // we'll "clamp" the distance between 5 and 25

        float distanceMod    = ofClamp(distance, 5., 25.);

        float strength        = (G * mass * moveStar.mass) / (distanceMod * distanceMod);

        glm::vec2 dirNorm   = dir / distance; 
        force    = dirNorm * strength;

    }
    return force;
}

void AttractStar::draw(){
    ofPushStyle();
    
    // hue based on mass
    float hue = ofMap(mass, 5, 30, 50, 255);
    ofColor color = ofColor::fromHsb(hue, 255, 240);
    
    ofSetColor(color, 127);
    
    // radius based on mass
    ofDrawCircle(pos, mass * 1.5);
    
    ofPopStyle();
}

void AttractStar::update(){
    float time = ofGetElapsedTimef();
    float sinTime = sin(time + mass*1.5) * (amplitude*mass);
    float cosTime = cos(time + mass*1.5) * (amplitude*mass);
    
    pos = glm::vec2(ofGetWidth()*0.5+cosTime, ofGetHeight()*0.5+sinTime);
}


