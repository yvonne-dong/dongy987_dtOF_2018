//reference: openframeworks particle example
#pragma once
#include "ofMain.h"

class Finn{
    
public:
    void setup(float posX, float posY, float width,
               float height, glm::vec2 acceleration);
    void update();
    void draw();
    void bounce();
    void addForce(glm::vec2 force);
    void damping();
    
    //float lerp;
    glm::vec2 pos;
    glm::vec2 lEyeP;
    glm::vec2 rEyeP;
    glm::vec2 vel;
    glm::vec2 mouse;
    glm::vec2 acc;
    
    
    ofColor color;
    ofColor faceC;
    
    float w, h, mouthX, mouthY, mouthH;
        
    //glm::vec2 windPoint; //mouse attract
//    glm::vec2 pos; //particle pos
//    glm::vec2 vel; //particle vel
};
