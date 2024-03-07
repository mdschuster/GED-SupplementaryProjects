#pragma once
#include "common.hpp"
#include "behavior.hpp"

class Mover{
    public:
        std::shared_ptr<Kinematic> kinematic;
        std::shared_ptr<Behavior> behavior;
        float mass=1.0f;
        float t=0.016f;
        float maxSpeed=200.0f;
        float maxAcceleration=1000.0f;
        
        Mover();
        Mover(Vec2 pos, Vec2 vel, float orientation);
        Mover(std::shared_ptr<Behavior> behavior, std::shared_ptr<Kinematic> target, Vec2 pos);
        void addForce(Vec2 force);
        void changeBehavior(std::shared_ptr<Behavior> behavior); 
        void update();

};