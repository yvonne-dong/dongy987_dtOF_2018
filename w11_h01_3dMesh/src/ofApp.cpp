#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gui.setup();
    gui.add( drawFaces.set("draw faces", true) );
    gui.add( drawWireframes.set("draw wires", false) );
    gui.add( drawVertices.set("draw vertices", false) );
    
    gui.add( mesh.noiseScale.set("noise scale", glm::vec2(.01), glm::vec2(0.), glm::vec2(.05)));
    gui.add( mesh.noiseFreq.set("frequency", 0.5, 0., 2.));
    gui.add( mesh.noiseAmp.set("amplitude", 40., 0., 100.));
    
    gui.add( mesh.colorNear.set("color near", ofColor::fuchsia, ofColor(0,0), ofColor(255,255,255,255)));
    gui.add( mesh.colorFar.set("color far", ofColor::navy, ofColor(0,0,0,0), ofColor(255,255,255,255)));
    
    mesh.setup(600,600, 100,100);
    /*
    ofSetFrameRate(60);
    image.load("comic.jpg");
    image.resize(200, 200);

    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableIndices();
    mesh.enableColors();

    float intensityThreshold = 100.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                glm::vec3 pos(x*4, y*4, z);
                mesh.addVertex(pos);
                mesh.addColor(c);

                offsets.push_back(glm::vec3(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }

    float connectionDistance = 20;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        glm::vec3 verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            glm::vec3 vertb = mesh.getVertex(b);
            glm::vec3 diff = verta - vertb;
            float distance = glm::length(diff);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    meshCopy = mesh;
    mouseDisplacement = false;
    */
}

//--------------------------------------------------------------
void ofApp::update(){
//    mesh.updateNoise();
    mesh.updateColors();
    
    /*
    if (mouseDisplacement) {
        glm::vec3 mouse(mouseX, ofGetHeight()-mouseY, 0);
        for (int i=0; i<mesh.getNumVertices(); ++i) {
            glm::vec3 vertex = meshCopy.getVertex(i);
            float distanceToMouse = glm::length(vertex - mouse);
            
            float displacement = ofMap(distanceToMouse, 0, 150, 10.0, 0, true);
            
            glm::vec3 dir = vertex - mouse;
            glm::vec3 normDir = dir/distanceToMouse;
            
            glm::vec3 displacedVertex = vertex + displacement*dir;
            mesh.setVertex(i, displacedVertex);
        }
    }
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        glm::vec3 vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        glm::vec3 timeOffsets = offsets[i];
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
    }
    */
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofEnableDepthTest();
    
    
    
    if (drawFaces){
        mesh.draw();
    }
    if (drawWireframes){
        mesh.drawWireframe();
    }
    if (drawVertices){
        mesh.drawVertices();
    }
    
    ofDisableDepthTest();
    
    cam.end();
    
    gui.draw();
    
    /*
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
     */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'm') {
        /*
        mouseDisplacement = !mouseDisplacement; // Inverts the boolean
        mesh = meshCopy; // Restore the original mesh
         */
    }
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
