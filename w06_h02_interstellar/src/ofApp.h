#pragma once

#include "ofMain.h"
#include "hoop.hpp"
#include "MoveStar.hpp"
#include "AttractStar.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyReleased(int key);
    
    vector<Hoop> hoop;
    vector<AttractStar> attractStars;
    vector<MoveStar> moveStars;
    
    //glm::vec2 mousePos;
    glm::vec2 center = glm::vec2(ofGetWidth()*.5,ofGetHeight()*.5);
};

