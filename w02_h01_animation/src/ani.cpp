#include "ani.h"

// --------------------------------------------------------
void Animation::setup(float posX, float posY, float width, float height, float ang){
    
    // setup position and size
    
    x1 = posX;
    y1 = posY;
    w = width;
    h = height;
    angDir = ang;
    x2 = x1 - w*0.5;
    y2 = y1 + h;
    x3 = x1 + w*0.5;
    y3 = y1 + h;
    angle = 0;
    
    
    // default to no movement yet - we can set it later
    
    dirX = 0;
    dirY = 0;
}

// --------------------------------------------------------
void Animation::update(){
    
    // move: update position x and y
    
    x1 += dirX;
//    x2 += dirX;
//    x3 += dirX;
    y1 += dirY;
    r = ofDist(x1, y1, ofGetWidth()*0.5, ofGetHeight()*0.5);
//    y2 += dirY;
//    y3 += dirY;
    
    
    // bounce:
    
    // check if we moved out of window frame
    
    if(x1 > ofGetWidth()){
        // if we're too far right...
        
        // bounce
        x1 = ofGetWidth();        // put back in window
        dirX = dirX * -1;        // flip x movement
        
    }
    else if (x1 < 0){
        // bounce off left edge
        
        x1 = 0;
        dirX = dirX * -1;
    }
    
    
    if(y1 > ofGetHeight()){
        // bounce bottom edge
        
        y1 = ofGetHeight();
        dirY = dirY * -1;
    }
    else if (y1 < 0){
        // or bounce top edge
        
        y1 = 0;
        dirY = dirY * -1;
    }
    
}

// --------------------------------------------------------
void Animation::draw(){
//    ofColor colorOne(ofMap(x1, 0, 1024, 0, 240), ofMap(y1, 0, 768, 0, 100), 50);
//    ofColor colorTwo(50, ofMap(x1, 0, 1024, 0, 100), ofMap(y1, 0, 768, 0, 240));
//    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
//    ofSetColor(255);
    ofPoint point;
    point.x = x1;
    point.y = y1;
    mouseX = int(ofGetMouseX());
    mouseY = int(ofGetMouseY());
    
    //ofDrawTriangle(x1,y1,x2,y2,x3,y3);
    ofPushMatrix();
    ofTranslate(point);
    ofRotateDeg(angle);
    ofSetColor(ofMap(x1, 0, 1024, 0, 240), ofMap(y1, 0, 768, 0, 100), 50);
    ofFill();
    ofDrawTriangle(0,0,-w*0.5,h,w*0.5,h);
    ofPopMatrix();
    //ofDrawLine(mouseX,mouseY,x1,y1);
    ofSetLineWidth(3);
    ofNoFill();
    ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, r);
    angle += (3 * angDir);
    
    cout << "mX " << mouseX << endl;
}

// --------------------------------------------------------
