//
//  Plane.cpp
//  w11_h01_3dMesh
//


#include "Plane.hpp"

Plane::Plane(){
    
}

void Plane::setup(float width, float height, float cols, float rows){
    for (int r = 0; r<rows; r++){
        for (int c=0; c<cols; c++){
            glm::vec3 pos;

            float halfWidth     = width * 0.5;
            float halfHeight    = height * 0.5;
            
            pos.x = ofMap(r, 0, rows-1, -halfWidth, halfWidth);
            pos.y = ofMap(c, 0, cols-1, halfHeight, -halfHeight);
            pos.z = 0;
            
            mesh.addVertex(pos);
            mesh.addColor(ofColor(255));
            if (r < rows-1 && c < cols-1){
                int index = r * cols + c;
                mesh.addIndex(index);
                mesh.addIndex(index + 1);
                mesh.addIndex(index + cols);
                
                mesh.addIndex(index + 1);
                mesh.addIndex(index + 1 + cols);
                mesh.addIndex(index + cols);
            }
        }
    }
}

void Plane::updateNoise(){
    
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<mesh.getVertices().size(); i++){
        glm::vec3& vertex = mesh.getVertices()[i];
        float noise =
        ofSignedNoise ( vertex.x * noiseScale.get().x,
                       vertex.y * noiseScale.get().y,
                       time * noiseFreq
                       );
        
        vertex.z = noise * noiseAmp;
        
    }
}

void Plane::updateColors(){
    for (int i=0; i<mesh.getVertices().size(); i++){
        glm::vec3& vertex = mesh.getVertices()[i];
        
        float depthPercent = ofMap(vertex.z, -noiseAmp, noiseAmp, 0, 1, true);    // map 0-1
        
        // lerp color
        ofColor color = colorFar.get().getLerped( colorNear.get(), depthPercent );
        
        mesh.setColor(i, color);        // set mesh color
    }
}

void Plane::draw(){
    
    ofPushMatrix();
    ofTranslate( getPosition() );
    ofScale( getScale() );
    mesh.draw();
    ofPopMatrix();
}

void Plane::drawWireframe(){
    ofPushMatrix();
    ofMultMatrix( getGlobalTransformMatrix() );
    mesh.drawWireframe();
    
    ofPopMatrix();
}

void Plane::drawVertices(){
    
    ofPushMatrix();
    ofMultMatrix( ofNode::getGlobalTransformMatrix() );
    for (int i=0; i<mesh.getVertices().size(); i++){
        ofPushStyle();
        glm::vec3 point   = mesh.getVertices()[i];
        
        if (mesh.getNumColors() > i){   // check for color
            ofSetColor( mesh.getColors()[i] );
        }
        ofDrawSphere( point, 1.f );
        
        ofPopStyle();
        
    }
    ofPopMatrix();
}






