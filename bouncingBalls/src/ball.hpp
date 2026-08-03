#pragma once

#include "vec2.hpp"

class Ball {
public:
    Vec2 pos;
    Vec2 vel;
    float radius;
    float mass;


    Ball(Vec2 pos, float radius, float mass);
    void move();
    void draw();


};

