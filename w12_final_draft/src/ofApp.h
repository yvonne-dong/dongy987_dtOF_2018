#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofPlanePrimitive    plane;
    ofSpherePrimitive   sphere;
    ofVideoGrabber      cam;
    ofPixels            previous;
    ofImage             diff;
    
    ofxPanel            gui;
    ofParameter<bool>   bTexture, bSolid, bWires;
    
    ofEasyCam   easyCam;
    // a scalar is like an ofVec4f but normally used for storing color information
    cv::Scalar  diffMean;
};
