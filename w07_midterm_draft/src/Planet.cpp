
#include "Planet.hpp"

Planet::Planet()
{
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    pos.z = ofRandom(-5, 5);
    mass  = ofRandom(5,20);
    amplitude = 5;
    setup();
}

Planet::Planet(glm::vec3 _pos, float _mass)
{
    pos     = _pos;
    mass  = ofClamp(_mass,5,20);
    amplitude = 50;
    setup();
}

void Planet::setup()
{
    
    float hue   = ofMap(mass, 5, 20, 250, 150);
    color       = ofColor::fromHsb(hue, 255, 255);
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
    ofSetColor(color);
    ofDrawCone(pos, mass* 1.5, mass* 3);
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
