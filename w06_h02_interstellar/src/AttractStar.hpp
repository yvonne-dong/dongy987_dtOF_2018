#pragma once
#include "ofMain.h"

#include "MoveStar.hpp"
// Attractor class will apply attraction force on Movers

class AttractStar {
public:
    
    AttractStar();        // default constructor
    AttractStar(glm::vec2 _pos, float _mass);    // alternative constructor
    
    glm::vec2 getForce(MoveStar m);
    
    void draw();
    void update();
    
    glm::vec2 pos;
    float mass;
    float amplitude, sinFrequency, cosFrequency;
    
    const float G = .4;        // gravitational constant
    // affects strength of gravity
    
};
