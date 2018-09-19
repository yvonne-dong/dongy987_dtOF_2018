#include "Portrait.h"

// --------------------------------------------------------
void Portrait::setup(float posX, float posY, float width, float height, float opacity){
    
    pos = glm::vec2(posX, posY);
    w = width;
    h = height;
    mouthH = 10;
    vel = glm::vec2(0, 0);
    a = opacity;
    
    color = ofColor(255);
    
}

// --------------------------------------------------------
void Portrait::update(){
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    pos += (mouse - pos) * lerp;
}

// --------------------------------------------------------
void Portrait::draw(){
    faceC = ofColor(255, 226, 239);
    lEyeP = glm::vec2(pos.x+w/2-20, pos.y+h/2-8);
    rEyeP = glm::vec2(pos.x+w/2+20, pos.y+h/2-8);
    mouthX = pos.x+w/2;
    mouthY = pos.y+h/2+15;
    //    ofColor colorOne(ofMap(x1, 0, 1024, 0, 240), ofMap(y1, 0, 768, 0, 100), 50);
    //    ofColor colorTwo(50, ofMap(x1, 0, 1024, 0, 100), ofMap(y1, 0, 768, 0, 240));
    //    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    //    ofSetColor(255);
//-------------------------circle--------------------------------
    ofSetColor(255, a);
    ofNoFill();
    int addX = 30;
    int addY = 30;
    ofSetLineWidth(2);
    for (int i = 0; i < 5; i ++){
        float time = ofGetElapsedTimef();
        ofDrawCircle(pos.x+w/2,pos.y+h/2,20+sin(time)*addX,20+sin(time)*addY);
        addX += i*10;
        addY += i*10;
    }
    ofSetLineWidth(1);
    //---------------------outerside-----------------------------
    ofSetColor(color);
    ofFill();
    ofDrawRectangle(pos.x,pos.y,w,h);
    ofDrawRectangle(pos.x,pos.y-10,20,h);
    ofDrawRectangle(pos.x+w-20,pos.y-10,20,h);
  //---------------------face-------------------------------------
    ofSetColor(faceC, a);
    ofFill();
    ofRectangle myFace;
    myFace.x = pos.x+10;
    myFace.y = pos.y+10;
    myFace.width = w-20;
    myFace.height = h-20;
    ofDrawRectRounded( myFace, 15 );
    ofSetColor(255, 0, 0);
  //------------------------mouth---------------------------------
    ofSetColor(255, 100, 100, a);
    ofFill();
    float dist = glm::distance(mouse,pos);
    mouthH = ofMap(dist, 0, 300, 5, 25);
    ofDrawEllipse(mouthX,mouthY,mouthH,mouthH);
  //--------------------------eyes--------------------------------
    ofSetColor(0, a);
    ofFill();
    ofDrawCircle(lEyeP.x,lEyeP.y,5,5);
    ofDrawCircle(rEyeP.x,rEyeP.y,5,5);
    ofSetColor(255);
}

// --------------------------------------------------------
//glm::vec2 Portrait::getCenter(){
//    float cx = pos.x + w * 0.5;
//    float cy = pos.y + h * 0.5;
//    return glm::vec2(cx, cy);
//}
//


