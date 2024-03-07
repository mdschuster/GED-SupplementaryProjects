#include "align.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

Align::Align() : Behavior(){
    maxAngularAcceleration=100.0f;
    maxRotation=100.0f;
}
Align::Align(std::shared_ptr<Kinematic> self, std::shared_ptr<Kinematic> target, float maxAngularAcceleration, float maxRotation) : Behavior(){
    this->self=self;
    this->target=target;
    this->maxAngularAcceleration=maxAngularAcceleration;
    this->maxRotation=maxRotation;
}
std::shared_ptr<SteeringOutput> Align::getSteering(){
//create shared pointer to hold steering
    auto steering=std::make_shared<SteeringOutput>();

    //get naive directon to the target
    float rotation=target->orientation-self->orientation;

    //map result to -pi to pi
    float rotationDirection=map(rotation,0.0f,360.0f,-M_PI,M_PI);
    float rotationSize=abs(rotationDirection);

    if(rotationDirection<targetRadius){
        steering->linearAccel=Vec2(0.0f,0.0f);
        steering->angularAccel=0.0f;
        return steering;
    }

    //target speed is based on if we are in the slow radius
    float targetSpeed=0.0f;
    if(rotationDirection>slowRadius){
        targetSpeed=maxSpeed;
    } else {
        targetSpeed=maxSpeed*rotationDirection/slowRadius;
    }

    // //the velocity we want is the direction and target speed
    // Vec2 targetVelocity=rotationDirection;
    // targetVelocity.normalize();
    // targetVelocity*=targetSpeed;


    // //Acceleration tries to get to the target velocity
    // steering->linearAccel=targetVelocity-self->velocity;
    // steering->linearAccel/=timeToTarget;

    // //set full acceleration along this direction
    // steering->linearAccel.normalize();
    // steering->linearAccel*=maxAcceleration;

    // //make sure we are not accelerating too fast
    // if(steering->linearAccel.length()>maxAcceleration){
    //     steering->linearAccel.normalize();
    //     steering->linearAccel*maxAcceleration;
    // }

    //output steering
    steering->angularAccel=0.0f;
}