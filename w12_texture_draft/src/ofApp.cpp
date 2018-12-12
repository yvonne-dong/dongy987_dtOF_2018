#include "ofApp.h"

const int width     = 100;
const int height    = 100;
const int nChannels = 4;

const int nBytes    = width * height * nChannels;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetSmoothLighting(true);
    ofSetFrameRate(60);
    sphere.set(50,15);
    
    light.setup();
    light.setDirectional();
    light.setDiffuseColor( ofColor::coral );
    light.setPosition(0, 0, 200);
    light.rotateDeg(225, 0, 1, 0);
    
    amplitude = 300;
    sinFrequency = 0.5;
    cosFrequency = 0.5;
    
    pixelData = new unsigned char[ nBytes ];
    img.getPixels().setFromExternalPixels(pixelData, width, height, nChannels);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef()* .1;
    float sinTime = sin(time * sinFrequency) * amplitude;
    float cosTime = cos(time * cosFrequency) * amplitude;
    mixOscillator   = glm::vec3(cosTime, sinTime,0);
    sphere.rotateDeg(0.5, 1,1,1);
    
    ofMesh& mesh = sphere.getMesh();
    for (int i=0; i<mesh.getVertices().size(); i++){
        glm::vec3& vertex   = mesh.getVertices()[i];
        float length = glm::length(vertex);
        glm::vec3 norm  = vertex / length;
        float noise     = ofSignedNoise(glm::vec3(time * .5) + norm * 2);
        vertex          = norm * (50 + noise * 5);
    }
    

    for (int i=0; i<nBytes; i+=nChannels){
        int x = (i/nChannels) % width;
        int y = (i/nChannels) / width;
        glm::vec2 noisePos       = glm::vec2(x,y) * 0.01f;
        pixelData[i]        = ofNoise(noisePos + glm::vec3(time)) * 255;        // red      - 1st byte/channel
        pixelData[i+1]      = ofNoise(noisePos + glm::vec3(time + 10)) * 255;   // green    - 2nd byte/channel
        pixelData[i+2]      = ofNoise(noisePos + glm::vec3(time + 20)) * 255;   // blue     - 3rd byte/channel
        pixelData[i+3]      = ofNoise(noisePos + glm::vec3(time + 30)) * 255;   // alpha    - 4th byte/channel
    }
    
    img.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofEnableLighting();
    ofEnableDepthTest();
    light.enable();
    light.draw();
    sphere.setPosition(mixOscillator);
    img.bind();
    sphere.draw();
    img.unbind();
    light.disable();
    ofDisableLighting();
    ofDisableDepthTest();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
