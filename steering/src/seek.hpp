#pragma once
#include "common.hpp"

class Seek: public Behavior{
    public:

        Seek();
        Seek(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration, float maxSpeed);

        std::shared_ptr<SteeringOutput> getSteering();
        const std::string getType() const;
};