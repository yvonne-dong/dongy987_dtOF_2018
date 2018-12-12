
#pragma once
#include "ofMain.h"

class Eyes {
public:
    
    Eyes();
    Eyes(glm::vec2 _eyePos, glm::vec2 _screenCenter, float _eyeSize, float _mouthSize);
    
    void update(glm::vec2 dir, float mouthMovement);
    void draw();
    void sleepMode();
    
    float eyeSize, mouthSize;
    glm::vec2 eyePos, eyeCenter;
};
