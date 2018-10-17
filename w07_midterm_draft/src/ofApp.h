#pragma once

#include "ofMain.h"
#include "Box.hpp"
#include "Planet.hpp"
#include "Moon.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
        vector<Planet> planets;
        vector<Moon> moons;
        Box box;
        ofEasyCam camera;
    
        glm::vec3 center   = glm::vec3(0,0,0);
};
