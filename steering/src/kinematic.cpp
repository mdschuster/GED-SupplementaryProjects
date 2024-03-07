#include "kinematic.hpp"

Kinematic::Kinematic() : position(Vec2(0.0f,0.0f)),orientation(0.0f), velocity(Vec2(0.0f,0.0f)), rotation(0.0f){}
Kinematic::Kinematic(Vec2 pos, float orientation, Vec2 velocity, float rotation): position(pos),orientation(orientation), velocity(velocity), rotation(rotation){}

void Kinematic::update(std::shared_ptr<SteeringOutput> const steering, float maxSpeed, float time){
    //update position and orientation
    position+=velocity*time;
    orientation+=rotation*time;

    //and the velocity and rotation
    velocity+=steering->linearAccel*time;
    orientation+=steering->angularAccel*time;

    //check for speeding and clip
    if(velocity.length()>maxSpeed){
        velocity.normalize();
        velocity*=maxSpeed;
    }
}