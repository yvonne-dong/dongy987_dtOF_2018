#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(){
    pos = glm::vec2(0,0);
}

ParticleSystem::ParticleSystem(glm::vec2 _pos){
    pos = _pos;
}

void ParticleSystem::applyForce(glm::vec2 force){
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyAcc(force);
        particles[i].applyDampingForce(0.1);
    }
}

void ParticleSystem::applyMouseForce(glm::vec2 mouseForce){
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyAcc(mouseForce);
    }
}

void ParticleSystem::update(int numNewParticles){
    for (int i=0; i<numNewParticles; i++){
        //glm::vec2 vel   = glm::vec2(ofRandom(-0.5, 0.5), 4);
        glm::vec2 vel   = glm::vec2(ofRandom(0, 0.5), 4);
        float mass      = ofRandom(1, 20);
        Particle particle = Particle(pos,vel,mass);
        particles.push_back(particle);
    }
    
    // update particles:
    for (int i=0; i<particles.size(); i++){
        glm::vec2 repulsion;
        glm::vec2 dir = mousePos - particles[i].pos;
        float distance = glm::length(dir);
        if (distance > 0) {
            glm::vec2 normalizedDir = glm::vec2(-1, -1) / distance;
            if (distance < 200) {
                repulsion = glm::vec2(normalizedDir.x, 0);
            }
        }
        
        cout<<dir<<endl;
        
        //applyMouseForce(repulsion);
        particles[i].bounceEdge();
        particles[i].update();
    }
    
    // erase bouced back particles:
    if (particles[0].vel.y < 2){
        particles.erase(particles.begin());
    }
    if (particles.size() > 200){
        particles.erase(particles.begin());
    }
}

void ParticleSystem::draw(){
    for (int i=0; i<particles.size(); i++){
            particles[i].draw();
    }
}

