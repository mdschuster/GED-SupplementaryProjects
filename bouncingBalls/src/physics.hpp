#pragma once

#include "ball.hpp"
#include <memory>

class Contact {
public:
    std::shared_ptr<Ball> a;
    std::shared_ptr<Ball> b;
    Vec2 normal;
    Vec2 start;
    Vec2 end;
    float depth;

    Contact(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b, Vec2 normal, Vec2 start, Vec2 end, float depth);
};

class Physics {
public:
    inline static float gravity = 20.0f;
    inline static float deltaTime=0.0f;
    float restitution;

    Physics(float restitution);
    Contact ballCollision(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b);
    void ballResolution(const Contact& c);



};

