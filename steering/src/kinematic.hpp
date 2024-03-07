#pragma once
#include "vec2.hpp"
#include "steeringoutput.hpp"
#include <memory>

class Kinematic{
    public:
        Vec2 position;
        float orientation;
        Vec2 velocity;
        float rotation;

        Kinematic();
        Kinematic(Vec2 pos, float orientation, Vec2 velociy, float rotation);

        void update(std::shared_ptr<SteeringOutput> const steering, float maxSpeed, float time);

};