

#pragma once
#include "ofMain.h"
#include "Moon.hpp"

class Planet
{
public:
    
    Planet();
    Planet(glm::vec3 _pos, float _mass);
    
    void setup();
    void update();
    void draw();
    
    glm::vec3 getForce(Moon m);
    
    void bounceBack(float left, float right, float top, float bottom, float front, float back);
    
    glm::vec3 pos, vel, acc;
    float mass, amplitude;
    float brightness;
    
    const float G = .4;
};
