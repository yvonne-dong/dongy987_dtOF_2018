#pragma once
#include "ofMain.h"

class Portrait {
public:
    void setup(float posX, float posY, float width, float height, float opacity);
    void update();
    void draw();

    float lerp; 
    glm::vec2 pos;
    float w, h, mouthX, mouthY, mouthH, a;
    glm::vec2 lEyeP;
    glm::vec2 rEyeP;
    glm::vec2 vel;
    //glm::vec2 getCenter();
    glm::vec2 mouse;
    ofColor color;
    ofColor faceC;
};
