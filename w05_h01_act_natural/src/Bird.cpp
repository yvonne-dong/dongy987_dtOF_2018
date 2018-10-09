//
//  Bird.cpp
//  w05_h01_act_natural
//
//  Created by Yanwen Dong on 2018/9/30.
//

#include "Bird.h"

Bird::Bird(float birdSize, float birdSpeed){
    size = birdSize;
    speed = birdSpeed;
}

//void Bird::setup(){
//    pos = glm::vec2(0,0);
//}

void Bird::update(glm::vec2 mousePos){
    //follow mouse
    glm::vec2 dir = mousePos - pos;
    pos += dir * speed;
    
    float angleR = atan2(dir.y, dir.x);
    angle = ofRadToDeg(angleR);
}

void Bird::draw(){
    float time = ofGetElapsedTimef();
    float range = 5;
    float wingFlap = sin(time*size)*size*2+10;
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateDeg(angle);
    
    ofPushStyle();
    ofSetColor(color);
    //draw bird - 4 points
    ofVec3f bTop = ofVec3f(0,0);
    ofVec3f bRight = bTop - ofVec3f(size*3,size+wingFlap);
    ofVec3f bLeft = bTop - ofVec3f(size*3,-size-wingFlap);
    ofVec3f bMid = bTop - ofVec3f(size*2.5, 0);
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    ofVertex(bTop);
    ofVertex(bLeft);
    ofVertex(bMid);
    ofVertex(bRight);
    ofEndShape();
    ofDrawLine(bTop, bMid);
    
    //ofDrawTriangle(p1,p2,p3);
    ofPopStyle();
    ofPopMatrix();          
}

void Bird::addRepulsion(Bird _b, float radius, float strength){
    glm::vec2 repPos = glm::vec2(_b.pos.x, _b.pos.y);
    glm::vec2 diff = pos - repPos;
    float length = diff.length();
    
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        //diff.normalize();
        frc.x = frc.x + diff.x * strength * pct;
        frc.y = frc.y + diff.y * strength * pct;
        _b.frc.x = _b.frc.x - diff.x * strength * pct;
        _b.frc.y = _b.frc.y - diff.y * strength * pct;
        cout<<"bAm = "<<bAmCloseEnough<<endl;
        
    }
}
