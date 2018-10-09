#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mouseReleased(int x, int y, int button);
    void keyReleased(int key);
    vector<ParticleSystem> particleSystems;
    glm::vec2 gravity;
    
    glm::vec2 pos1 = glm::vec2(ofGetWidth() * 0.5-250, 100);
    float count = 1;
    //glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
};
