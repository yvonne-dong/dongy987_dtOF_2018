#include "ani.hpp"

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
    
//    if (mP){
//        cout << "press " << "success" << endl;
//        x1 += dirX;
//        y1 += dirY;
//    }
    x1 += dirX;
    y1 += dirY;
    x2 += dirX;
    y2 += dirY;
    x3 += dirX;
    y3 += dirY;
    
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
    
    ofPushMatrix();
    ofTranslate(point);
    ofRotateDeg(angle);
    ofSetColor(ofMap(x1, 0, 1024, 0, 240), ofMap(y1, 0, 768, 0, 100), 50);
    ofSetLineWidth(3);
    ofNoFill();
    //ofFill();
    ofDrawTriangle(0,0,-w*0.5,h,w*0.5,h);
    ofPopMatrix();
    ofDrawLine(mouseX,mouseY,x1,y1);
    //ofDrawCircle(ofGetWidth()*0.5, ofGetHeight()*0.5, r);
    angle += (3 * angDir);
    
//    cout << "mX " << mouseX << endl;
}

// --------------------------------------------------------
//void Animation::mousePressed(int x, int y, int button){
//    mP = true;
//}
//
//--------------------------------------------------------------
//void Animation::mouseReleased(int x, int y, int button){
//    mP = false;
//}
