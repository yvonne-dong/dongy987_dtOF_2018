
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(255,0,130);
    
    potValue = "analog pin:";
    
    font.load("franklinGothic.otf", 20);
    smallFont.load("franklinGothic.otf", 14);
    
    ard.connect("/dev/cu.usbmodem1411", 57600);
    
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino    = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();
    
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    bSetupArduino = true;
    
    /*
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    */
    
    //A0 - analog input
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    
    
    // Listen for changes (digital and analog pins)
//    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
    // update the arduino, get any data or messages.
    // the call to ard.update() is required
    ard.update();
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
//    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
    
    raw = ard.getAnalog(pinNum);
    if (raw)
    {
        buffer = raw * Vin;
        Vout = (buffer) / 1024.0;
        buffer = (Vin / Vout) - 1;
        R2 = R1 * buffer;
        R2Value = "R2 Value: " + ofToString(R2);
//        Serial.print("Vout: ");
//        Serial.println(Vout);
//        Serial.print("R2: ");
//        Serial.println(R2);
//        delay(1000);
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    bgImage.draw(0,0);
    
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 127);
    ofDrawRectangle(510, 15, 275, 150);
    ofDisableAlphaBlending();
    
    ofSetColor(255, 255, 255);
    if (!bSetupArduino){
        font.drawString("arduino not ready...\n", 515, 40);
    } else {
        font.drawString(potValue + "\n" + R2Value, 515, 40);
        ofSetColor(64, 64, 64);
        ofSetColor(255, 255, 255);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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
