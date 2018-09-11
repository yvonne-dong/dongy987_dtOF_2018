#pragma once
#include "ofMain.h"

class Animation {
public:
    void setup(float posX, float posY, float width, float height, float ang);
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    // some extra "utility" functions -
    // return the center coordinates
    int mouseX, mouseY;
    float x1, y1, x2, y2, x3, y3, w, h, r;
    float dirX, dirY;
    float angle, angDir;
//    bool mP = false;
};

