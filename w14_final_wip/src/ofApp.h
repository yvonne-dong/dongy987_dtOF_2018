#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h" //openCv library
#include "ofxCv.h" //capatability
#include "ofEvents.h"
#include "Eyes.hpp"

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void stopSound(int _soundNum);
    
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
		
        ofPath setFace(glm::vec2 centerPos, int radius);
        float w, h;
        ofVideoGrabber cam;
        ofImage mirrorCam;

        ofRectangle bound;
        ofxCv::ObjectFinder finder; //find face
        glm::vec2 screenCenter, faceCenter, direction;
    
        vector<ofMesh> faces;
        vector<ofImage> textureImg;
        vector<Eyes> allEyes;
        vector<bool> updateFace;
        vector<float> updateWobbly;
    
        ofArduino ard;
        vector<ofSoundPlayer> sounds;
        float soundNum;
        bool bSetupArduino;
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
    void updateArduino();
    
    void calculateResistance(int _pinNum);
    string buttonState;
    
    vector<string> valAnalog;
    vector<string> valResistance;
    vector<float> fValResistance;
};
