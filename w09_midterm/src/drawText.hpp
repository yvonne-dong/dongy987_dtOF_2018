

#pragma once
#include "ofMain.h"
#include "TextParticle.hpp"

class Text {
    
public:
    
    //constructors
    Text(uint32_t _letter);
    Text(uint32_t _letter, glm::vec3 _pos);
    ofTrueTypeFont testFont;
    ofPath testCharContour;
    uint32_t letter;
    
    //functions
    void applyForce(glm::vec3 force); //force that dissolve the text shape
    //assign contour pos to particles
    void update();
    void draw();
    
    glm::vec3 pos, forceP;
    
    
    vector<TextParticle> textParticles;
};
