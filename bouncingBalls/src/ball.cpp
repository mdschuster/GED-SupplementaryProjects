#include "ball.hpp"
#include "physics.hpp"

#include "raylib.h"


Ball::Ball(Vec2 pos, float radius, float mass): pos(pos), radius(radius), mass(mass) {}

void Ball::move() {
    vel.y=vel.y+Physics::gravity*Physics::deltaTime;
    pos=pos+vel*Physics::deltaTime;
}

void Ball::draw() {
    DrawCircle(static_cast<int>(pos.x),static_cast<int>(pos.y), radius, ColorFromNormalized(Vector4(1.0f,0.0f,0.0f,1.0f)));
}