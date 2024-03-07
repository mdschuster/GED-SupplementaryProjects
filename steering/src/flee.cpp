#include "flee.hpp"

Flee::Flee(){
    maxAcceleration=0.0f;
}
Flee::Flee(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration) {
    this->self=self;
    this->target=target;
    this->maxAcceleration=maxAcceleration;
}
const std::string Flee::getType() const{
    return "Flee";
}

std::shared_ptr<SteeringOutput> Flee::getSteering(){

    //create shared pointer to hold steering
    auto steering=std::make_shared<SteeringOutput>();

    //get vector to target
    steering->linearAccel=self->position-target->position;

    //set full acceleration along this direction
    steering->linearAccel.normalize();
    steering->linearAccel*=maxAcceleration;
    
    //output steering
    steering->angularAccel=0.0f;
    return steering;

}