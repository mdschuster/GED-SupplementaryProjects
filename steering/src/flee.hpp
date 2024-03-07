#pragma once
#include "common.hpp"

class Flee : public Behavior{
    public:

        Flee();
        Flee(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration);

        std::shared_ptr<SteeringOutput> getSteering();
        const std::string getType() const;
};