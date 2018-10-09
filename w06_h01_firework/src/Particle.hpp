#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void applyAcc(glm::vec2 force);
    void applyDampingForce(float strength);
    void update();
    void draw();
    
    void wordSetup(); //setting up the chosen word particle
    void bounceEdge(); //back from the edge
    
    glm::vec2 pos, vel, acc;
    float mass;
    
    vector<string> word; //set up the vector for the words
    string chosenWord; //assigning the chosen word
};
