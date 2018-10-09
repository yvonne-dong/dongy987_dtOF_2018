#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);
    
    void applyForce(glm::vec2 force);
    void applyMouseForce(glm::vec2 mouseForce);
    
    void update(int numNewParticles = 1);
    void draw();
    
    glm::vec2 pos;    
    vector<Particle> particles;
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
};
