
#pragma once
#include "ofMain.h"

class Moon {
    
public:
    
    // constructors
    Moon();
    Moon(glm::vec3 _pos, float _mass);
    
    // functions
    void applyForce(glm::vec3 force);
    void applyDampingForce(float strength);
    
    void bounceBack(float left, float right, float top, float bottom, float front, float back);   // keep Mover on screen
    
    void update();
    void draw();
    
    glm::vec3 pos, vel, acc;
    float mass;
};
