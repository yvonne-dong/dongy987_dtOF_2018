#pragma once
#include "ofMain.h"

class Animation {
public:
    void setup(float posX, float posY, float width, float height, float ang);
    void update();
    void draw();
//    void keyReleased(int key);
    
    // some extra "utility" functions -
    // return the center coordinates
    int mouseX, mouseY;
    
    float x1, y1, x2, y2, x3, y3, w, h, r;
    float dirX, dirY;
    float angle, angDir;
    
};

