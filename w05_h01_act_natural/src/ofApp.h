#pragma once

#include "ofMain.h"
#include "Bird.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        //Bird birds;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        vector<Bird> birds;
        glm::vec2 pressedPos =
        glm::vec2 (ofGetWidth()*0.5, ofGetHeight()*0.5);
        int birdNum = 50;
};
