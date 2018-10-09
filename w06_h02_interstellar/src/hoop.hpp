#pragma once
#include "ofMain.h"

class Hoop {
    
public:
    
    Hoop();
    Hoop(glm::vec2 _pos, float _mass);
    
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void applyElasticForce();
    
    void bounceEdge();
    
    void update();
    void draw();
    
    glm::vec2 originPos, pos, vel, acc;
    float mass;
    
};
