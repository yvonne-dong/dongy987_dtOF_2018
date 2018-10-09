#pragma once
#include "ofMain.h"

class MoveStar {
    
public:
    
    // constructors
    MoveStar();
    MoveStar(glm::vec2 _pos, float _mass);
    
    // functions
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    
    void bounceWindowEdges();   // keep Mover on screen
    
    void update();
    void draw();
    
    // variables
    glm::vec2 pos, vel, acc;
    float mass;
    
};
