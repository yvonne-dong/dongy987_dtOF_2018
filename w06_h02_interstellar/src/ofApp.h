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
    
    float mainHoopSize = TWO_PI/.05;
    vector<Hoop> hoop;
    vector<AttractStar> attractStars;
    vector<MoveStar> moveStars;
    
    glm::vec2 center = glm::vec2(ofGetWidth()*.5,ofGetHeight()*.5);
};

