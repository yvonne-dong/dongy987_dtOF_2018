
#include "Planet.hpp"

Planet::Planet()
{
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    pos.z = ofRandom(-5, 5);
    mass  = ofRandom(10,30);
    amplitude = 5;
    setup();
}

Planet::Planet(glm::vec3 _pos, float _mass)
{
    pos     = _pos;
    mass  = ofClamp(_mass,10,30);
    amplitude = 50;
    setup();
}

void Planet::setup()
{
    brightness   = ofMap(mass,10,30,250,150);
}

void Planet::update()
{
    //    float time = ofGetElapsedTimef();
    //    float sinTime = sin(time + mass*1.5) * (amplitude*mass);
    //    float cosTime = cos(time + mass*1.5) * (amplitude*mass);
    //
    //    pos = glm::vec3(ofGetWidth()*0.5+cosTime, ofGetHeight()*0.5+sinTime,ofGetWidth()*0.5+cosTime);
}

void Planet::draw()
{
    ofPushStyle();
    ofSetColor(brightness,brightness,brightness);
    //ofFill();
    ofDrawCone(pos, mass*6, mass*9);
    ofSetColor(brightness,brightness,brightness,50);
    ofFill();
    ofDrawCone(pos, mass*6, mass*9);
    ofPopStyle();
}

glm::vec3 Planet::getForce(Moon moon)
{
    glm::vec3 force = glm::vec3(0,0,0);
    glm::vec3 dir    = pos - moon.pos;
    float distance    = glm::length(dir);
    
    if (distance > 0) {
        // gravity magnitude = (G * mass1 * mass2) / (distance * distance)
        // we'll "clamp" the distance between 5 and 25
        
        float distanceMod    = ofClamp(distance, 5., 25.);
        
        float strength        = (G * mass * moon.mass) / (distanceMod * distanceMod);
        
        glm::vec3 dirNorm   = dir / distance;
        force    = dirNorm * strength;
    }
    return force;
}
