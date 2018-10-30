

#include "drawText.hpp"
const int nText = 50;

Text::Text(uint32_t _letter){
    pos = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    //set the input letter
    letter = _letter;
    testFont.load("kenpixel.ttf", 12, true, true, true);
    bool vflip = true;
    bool filled = true;
    filled = false;
    testCharContour = testFont.getCharacterAsPoints(letter, vflip, filled);
    
    for (int i=0; i<nText; i++){
        TextParticle textParticle =TextParticle();
        textParticles.push_back(textParticle);
    }
}

Text::Text(uint32_t _letter, glm::vec3 _pos){
    pos = _pos;
    letter = _letter;
    //set the input letter
    testFont.load("kenpixel.ttf", 12, true, true, true);
    bool vflip = true;
    bool filled = true;
    filled = false;
    testCharContour = testFont.getCharacterAsPoints(letter, vflip, filled);
    for (int i=0; i<nText; i++){
        for (int j = 0; j < (int)testCharContour.getOutline().size(); j ++) {
            ofPolyline outline = testCharContour.getOutline()[j].getResampledBySpacing(2);
            for(int k = 0; k < outline.size(); k++){
                glm::vec3 thisPoint = glm::vec3(outline[k].x+pos.x, -outline[k].y-pos.y,pos.z);
                TextParticle textParticle =TextParticle();
                textParticle.pos = thisPoint;
                textParticles.push_back(textParticle);
            }
        }
    }
}

void Text::update(){
    for (int i=0; i<nText; i++){
        textParticles[i].update();
    }
}

void Text::applyForce(glm::vec3 force){
    forceP = force;
    for (int i=0; i<nText; i++){
        forceP.x = ofRandom(-force.x,force.x);
        forceP.y = ofRandom(-force.y,force.y);
        forceP.z = ofRandom(-force.z,force.z);
        textParticles[i].applyForce(forceP);
    }
}

void Text::draw(){
    for (int i=0; i<nText; i++){
        textParticles[i].draw();
    }
}


