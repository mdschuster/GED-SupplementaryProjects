#pragma once
#include "common.hpp"

class Arrive : public Behavior{
    public:


        Arrive();
        Arrive(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration, float maxSpeed);
        std::shared_ptr<SteeringOutput> getSteering();
        virtual const std::string getType() const;

};