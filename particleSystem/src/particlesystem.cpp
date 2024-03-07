#include "particlesystem.hpp"
#include <random>
#include <iostream>
#include "profiler.hpp"

ParticleSystem::ParticleSystem(){}
void ParticleSystem::init(Vec2 position, Vec2 windowSize){
    this->position=position;
    this->windowSize=windowSize;
    resetParticles();
}
void ParticleSystem::update(std::string domColor){
    PROFILE_FUNCTION();
    for(int i=0;i<particles.size();i++){
        auto& p = particles[i];
        if(p.lifetime<=0){
            resetParticle(i,domColor);
        }
        p.position+=p.velocity;
        p.lifetime--;
        int alpha=255*(float)p.lifetime/p.startLifeTime;
        if(p.color.a!=0)p.color.a=alpha;
    }
}

void ParticleSystem::draw(){
    PROFILE_FUNCTION();
    for(int i=0;i<particles.size();i++){
        auto& p = particles[i];
        DrawRectanglePro({p.position.x,p.position.y,size,size}, {size/2,size/2}, 0.0f, p.color);
    }
}

void ParticleSystem::resetParticles(int count, float size){
    PROFILE_FUNCTION();
    particles=std::vector<Particle>(count);
    this->size=size;
    for(int i=0;i<particles.size();i++){
        resetParticle(i,"RED",true);
    }
}

void ParticleSystem::resetParticle(int index, std::string domColor,bool first){
    auto& p = particles[index];

    float x = position.x;
    float y = position.y;
    p.position={x,y};

    p.lifetime=30+rand()%120;
    p.startLifeTime=p.lifetime;
    
    if(domColor=="RED") p.color=Color((int)128+rand()%128,50,50,255);
    if(domColor=="BLUE") p.color=Color(50,50,(int)128+rand()%128,255);
    if(domColor=="GREEN") p.color=Color(50,(int)128+rand()%128,50,255);
    if(first) p.color.a=0;

    float rx=((float)rand()/RAND_MAX-0.5f)*5;
    float ry=((float)rand()/RAND_MAX-0.5f)*5;
    p.velocity=Vec2(rx,ry);
    p.velocity.normalize();
    p.velocity*=1+((float)rand()/RAND_MAX)*2;


}