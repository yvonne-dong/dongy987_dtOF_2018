
#pragma once
#include "ofMain.h"

class Round {
    
public:
    Round();
    Round(glm::vec3 _pos);
    
    void update();
    void draw();
    
    ofSpherePrimitive sphere;
};
