#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlSettings.h"
#include "Plane.hpp"

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
		
    Plane mesh;
    ofxPanel gui;
    ofParameter<bool> drawFaces, drawWireframes, drawVertices;
    
    
//    ofMesh mesh;
//    ofMesh meshCopy;
//    ofImage image;
    ofEasyCam cam;
    vector<glm::vec3> offsets;
    bool mouseDisplacement;
};
