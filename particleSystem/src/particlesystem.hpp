#pragma once
#include <vector>
#include <string>
#include <include/raylib.h>
#include "vec2.hpp"

struct Particle{
    Vec2 position;
    Vec2 velocity;
    Color color;
    int lifetime=0;
    int startLifeTime=0;
    float speed=0;
};

class ParticleSystem{
    std::vector<Particle> particles;
    
    Vec2 windowSize;
    float size=10;

    void resetParticle(int index, std::string domColor,bool first=false);

    public:
        Vec2 position;
        void resetParticles(int count=8192, float size=5);
        ParticleSystem();
        void init(Vec2 position, Vec2 windowSize);
        void update(std::string domColor);
        void draw();

};