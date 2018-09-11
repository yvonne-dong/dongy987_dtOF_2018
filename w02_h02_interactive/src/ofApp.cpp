#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);    // set background black
    
    //    ani.setup(ofGetWidth()*0.5, ofGetHeight()*0.5, 50, 50);
    //
    // set starting movement direction
    
    //    ani.dirX = 5;        // move 5 pixels right per frame to start
    //    ani.dirY = 5;        // move 5 pixels down per frame
    
    
    for (int i=0; i<50; i++){
        
        float w = ofRandom(20, 80);
        float h = w;
        float x = ofGetWidth()*0.5;
        float y = ofGetHeight()*0.5;
        float angleDir = ofRandom(-1, 1);
        
        ani[i].setup(ofGetWidth()*0.5, ofGetHeight()*0.5, w, h, angleDir);
        
        // set starting movement direction
        
        ani[i].dirX = ofRandom(-6, 6);        // move 5 pixels right per frame to start
        ani[i].dirY = ofRandom(-6, 6);        // move 5 pixels down per frame
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (mP){
        cout << "on" <<endl;
        for (int i=0; i<50; i++){
            ani[i].update();        // move and bounce off walls
        }
    } else {
        cout << "off" <<endl;
    }
//    for (int i=0; i<10; i++){
//        ani[i].update();        // move and bounce off walls
//    }       // move and bounce off walls
}

//--------------------------------------------------------------
void ofApp::draw(){

    //    mouseX = int(ofGetMouseX());
    //    mouseY = int(ofGetMouseY());
    for (int i=0; i<50; i++){
        ani[i].draw();        // move and bounce off walls
    }
    //cout << "mX " << mouseX << endl;
    // draw to screen
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    // some extra keyboard commands:
    
    if (key == 'f') {
        
        // press f to toggle fullscreen / window mode
        ofToggleFullscreen();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mP = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mP = false;
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
