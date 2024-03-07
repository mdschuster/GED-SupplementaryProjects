#include "arrive.hpp"

Arrive::Arrive(){
    maxAcceleration=0.0f;
    maxSpeed=0.0f;
}
Arrive::Arrive(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAcceleration, float maxSpeed){
    this->self=self;
    this->target=target;
    this->maxAcceleration=maxAcceleration;
    this->maxSpeed=maxSpeed;
}
const std::string Arrive::getType() const {
    return "ARRIVE";
}
std::shared_ptr<SteeringOutput> Arrive::getSteering(){
    //create shared pointer to hold steering
    auto steering=std::make_shared<SteeringOutput>();

    //get vector to target
    Vec2 direction=target->position-self->position;
    float distance=direction.length();

    if(distance<targetRadius){
        steering->linearAccel=Vec2(0.0f,0.0f);
        steering->angularAccel=0.0f;
        return steering;
    }

    //target speed is based on if we are in the slow radius
    float targetSpeed=0.0f;
    if(distance>slowRadius){
        targetSpeed=maxSpeed;
    } else {
        targetSpeed=maxSpeed*distance/slowRadius;
    }

    //the velocity we want is the direction and target speed
    Vec2 targetVelocity=direction;
    targetVelocity.normalize();
    targetVelocity*=targetSpeed;


    //Acceleration tries to get to the target velocity
    steering->linearAccel=targetVelocity-self->velocity;
    steering->linearAccel/=timeToTarget;

    //set full acceleration along this direction
    steering->linearAccel.normalize();
    steering->linearAccel*=maxAcceleration;

    //make sure we are not accelerating too fast
    if(steering->linearAccel.length()>maxAcceleration){
        steering->linearAccel.normalize();
        steering->linearAccel*maxAcceleration;
    }

    //output steering
    steering->angularAccel=0.0f;
    return steering;
}