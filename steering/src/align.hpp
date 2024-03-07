#pragma once
#include "common.hpp"

class Align : public Behavior{
    public:

        Align();
        Align(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAngularAcceleration, float maxRotation);

        std::shared_ptr<SteeringOutput> getSteering();
};