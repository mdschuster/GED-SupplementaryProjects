#include "seek.hpp"
#include <iostream>

Seek::Seek() : Behavior() {
    maxAcceleration=0.0f;
    maxSpeed=0.0f;
}
Seek::Seek(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration, float maxSpeed)  : Behavior() {
    this->self=self;
    this->target=target;
    this->maxAcceleration=maxAcceleration;
    this->maxSpeed=maxSpeed;
}
const std::string Seek::getType() const{
    return "SEEK";
}

std::shared_ptr<SteeringOutput> Seek::getSteering(){

    //create shared pointer to hold steering
    auto steering=std::make_shared<SteeringOutput>();

    //get vector to target
    steering->linearAccel=target->position-self->position;

    //set full acceleration along this direction
    steering->linearAccel.normalize();
    steering->linearAccel*=maxAcceleration;

    //output steering
    steering->angularAccel=0.0f;
    return steering;

}