#pragma once
#include "ofMain.h"

class TextParticle {
public:
    
    TextParticle();
    TextParticle(glm::vec3 _pos);
    
    //functions
    //void assignPos(glm::vec3 particlePos);
    void applyForce(glm::vec3 force); //force that dissolve the text shape
    void bounceBack(float left, float right, float top, float bottom, float front, float back);   // keep particles on screen
    void update();
    void draw();
    
    glm::vec3 pos, vel, acc;
    glm::vec3 parameter;
    float mass;
    float bornTime;
    bool fade;
};
