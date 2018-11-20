

#pragma once
#include "ofMain.h"

class Plane : public ofNode {
public:
    
    Plane();
    void setup(float width, float height, float cols, float rows);
    
    void updateColors();
    void updateNoise();
    void draw();
    void drawWireframe();
    void drawVertices();
    
    ofMesh mesh;
    ofParameter<ofColor> colorNear, colorFar;
    ofParameter<float> noiseAmp;
    ofParameter<float> noiseFreq;
    ofParameter<glm::vec2> noiseScale;
};
