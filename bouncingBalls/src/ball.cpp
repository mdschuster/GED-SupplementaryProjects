#include "ball.hpp"
#include "physics.hpp"

#include "raylib.h"


Ball::Ball(Vec2 pos, Vec2 vel,float radius, float mass, int windowWidth,int windowHeight): pos(pos),vel(vel), radius(radius), mass(mass),windowWidth(windowWidth),windowHeight(windowHeight) {}

void Ball::move() {
    vel.y=vel.y+Physics::gravity*Physics::deltaTime;
    pos=pos+vel*Physics::deltaTime;
    if (pos.x < 0+radius || pos.x + radius > windowWidth) {
        vel.x *= -1;
        pos.x = std::clamp(pos.x, radius, windowWidth - radius);
    }
    if (pos.y < 0+radius || pos.y + radius > windowHeight) {
        vel.y *= -1;
        pos.y = std::clamp(pos.y, radius , windowHeight - radius);
    }
}

void Ball::draw() {
    DrawCircle(static_cast<int>(pos.x),static_cast<int>(pos.y), radius, ColorFromNormalized(Vector4(1.0f,0.0f,0.0f,1.0f)));
}