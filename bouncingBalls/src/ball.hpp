#pragma once

#include "vec2.hpp"

class Ball {
public:
    Vec2 pos;
    Vec2 vel;
    float radius;
    float mass;
    int windowWidth;
    int windowHeight;


    Ball(Vec2 pos, Vec2 vel,float radius, float mass, int windowWidth,int windowHeight);
    void move();
    void draw();


};

