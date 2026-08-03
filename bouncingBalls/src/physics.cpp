//
// Created by Micah Schuster on 8/3/26.
//

#include "physics.hpp"
Physics::Physics(float restitution) : restitution(restitution) {}



Contact Physics::ballCollision(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b) {

    //detect:
    float dist=sqrt(a->pos.x*a->pos.x+a->pos.y*a->pos.y);
    if (dist<a->radius+b->radius) {
        //compute normal
        Vec2 normal=(b->pos-a->pos);
        normal.normalize();
        //compute start
        Vec2 start=a->pos+normal*a->radius;
        //compute end
        Vec2 end=b->pos-normal*b->radius;
        //compute depth
        float depth=a->radius+b->radius-dist;
        Contact c = Contact(a,b,normal,start,end,depth);
        return c;
    } else {
        Contact c = Contact(a,b,Vec2(0,0),Vec2(0,0),Vec2(0,0),-1);
        return c;
    }

}

void Physics::ballResolution(const Contact& c) {
    if (c.depth<0) return;

}


Contact::Contact(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b, Vec2 normal, Vec2 start, Vec2 end, float depth): a(a), b(b), normal(normal), start(start), end(end), depth(depth) {}