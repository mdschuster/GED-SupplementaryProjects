#pragma once
#include "kinematic.hpp"
#include <memory>
#include <string>

class Behavior{
    public:

        //kinematic data for self and target
        std::shared_ptr<Kinematic> self;
        std::shared_ptr<Kinematic> target;

        //max acceleration for  self
        float maxAcceleration;
        float maxAngularAcceleration;
        float maxRotation;
        float maxSpeed;
        float targetRadius=1;
        float slowRadius=100;
        float timeToTarget=0.1f;

        Behavior();
        virtual std::shared_ptr<SteeringOutput> getSteering()=0;
        virtual const std::string getType() const=0;
        float map(float x, float in_min, float in_max, float out_min, float out_max);
        float mapToRange (float rotation);
};