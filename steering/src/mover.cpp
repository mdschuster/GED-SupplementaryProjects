#include "mover.hpp"
#include <iostream>


Mover::Mover(){}
Mover::Mover(Vec2 pos, Vec2 vel, float orientation) {
    kinematic=std::make_shared<Kinematic>(pos,orientation,vel,0.0f);
}
Mover::Mover(std::shared_ptr<Behavior> behavior, std::shared_ptr<Kinematic> target, Vec2 pos) {
    kinematic=std::make_shared<Kinematic>();
    kinematic->position=pos;
    kinematic->velocity=Vec2(0.0f,0.0f);
    kinematic->orientation=0.0f;
    kinematic->rotation=0.0f;

    this->behavior=behavior;
    this->behavior->target=target;
    this->behavior->self=kinematic;
    this->behavior->maxAcceleration=maxAcceleration;
    this->behavior->maxSpeed=maxSpeed;
    
}

void Mover::update(){
    auto steering=behavior->getSteering();
    kinematic->update(steering, behavior->maxSpeed,0.016f);
}

void Mover::changeBehavior(std::shared_ptr<Behavior> behavior){
    auto oldTarget= this->behavior->target;
    this->behavior=behavior;
    this->behavior->target=oldTarget;
    this->behavior->self=kinematic;
    this->behavior->maxAcceleration=maxAcceleration;
    this->behavior->maxSpeed=maxSpeed;
}