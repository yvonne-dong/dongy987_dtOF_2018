/*
 reference - https://github.com/kylemcdonald/ofxCv/tree/master/example-difference
 */

#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    cam.setup(640, 480);
    
    float aspectRatio = cam.getWidth() / cam.getHeight();
    float w = ofGetWidth()-200;
    float h = w / aspectRatio;
    
    // imitate() will set up previous and diff
    // so they have the same size and type as cam
    imitate(previous, cam);
    imitate(diff, cam);
    
    plane.set(w, h, 100, 100);
    plane.mapTexCoordsFromTexture(diff.getTexture());
    sphere.set(200, 20);
    sphere.mapTexCoordsFromTexture(diff.getTexture());
    sphere.rotateDeg(30, glm::vec3(1,0,0));
    
    gui.setup();
    gui.add( bTexture.set("use texture", true) );
    gui.add( bWires.set("draw wireframe", true) );
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        // take the absolute difference of prev and cam and save it inside diff
        absdiff(cam, previous, diff);
        diff.update();
        // like ofSetPixels, but more concise and cross-toolkit
        copy(cam, previous);
        // mean() returns a Scalar. it's a cv:: function so we have to pass a Mat
        diffMean = mean(toCv(diff));
        // you can only do math between Scalars,
        // but it's easy to make a Scalar from an int (shown here)
        diffMean *= Scalar(50);
        
        //ofMesh& mesh = sphere.getMesh();
        ofMesh& mesh = plane.getMesh();
        for (int i=0; i<mesh.getVertices().size(); i++){
            auto& vertex = mesh.getVertices()[i];
            float w     = plane.getWidth();
            float h     = plane.getHeight();
            float imgX  = ofMap(vertex.x, -w*0.5, w*0.5, 0, cam.getWidth()-1);
            float imgY  = ofMap(vertex.y, h*0.5, -h*0.5, 0, cam.getHeight()-1);
            
            ofColor color       = diff.getPixels().getColor(imgX, imgY);
            float brightness    = color.getBrightness();
            
            vertex.z = brightness;
        }
    }
    
    //cone.rotateDeg(.05, glm::vec3(0,1,0));
}

void ofApp::draw() {
    easyCam.begin();
    ofEnableDepthTest();
    
    ofSetColor(255);
    //cam.draw(0, 0);
    //diff.draw(-ofGetWidth()*0.5, -ofGetHeight()*0.5, 0);
    
    // use the [] operator to get elements from a Scalar
    float diffRed = floor(diffMean[0]);
    float diffGreen = floor(diffMean[1]);
    float diffBlue = floor(diffMean[2]);
    //46-2000
//    cout<<diffRed<<endl;
//    ofSetColor(255, 0, 0);
//    ofDrawCircle(0, 0, diffRed);
//    ofSetColor(0, 255, 0);
//    ofDrawCircle(0, 0, diffGreen);
//    ofSetColor(0, 0, 255);
//    ofDrawCircle(0, 0, diffBlue);
    
    
    if (bTexture) {
        diff.bind();
    }
    plane.draw();
    //sphere.draw();
    
    if (bTexture) {
        diff.unbind();
    }
    
    if (bWires){
        ofPushStyle();
        ofSetColor(127,127);
        plane.drawWireframe();
        //sphere.drawWireframe();
        ofPopStyle();
    }
    
    ofDisableDepthTest();
    easyCam.end();
    
    gui.draw();
}
