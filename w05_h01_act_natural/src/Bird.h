//
//  Bird.h
//  w05_h01_act_natural
//
//  Created by Yanwen Dong on 2018/9/30.
//

#pragma once
#include "ofMain.h"

//class Bird
class Bird {
public:
    
    Bird( float birdSize = 10., float birdSpeed = 1.);
    
    void setup();
    void update(glm::vec2 mousePos);
    void draw();
    void addRepulsion(Bird _b, float radius, float strength);
    
    float size;
    float speed;
    ofColor color = ofColor::white;
    
    glm::vec2 pos;
    glm::vec2 frc;
    float angle;
};
