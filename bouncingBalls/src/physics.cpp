//
// Created by Micah Schuster on 8/3/26.
//

#include "physics.hpp"
Physics::Physics(float restitution) : restitution(restitution) {}



Contact Physics::ballCollision(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b) {

    //detect:
    float dist=a->pos.dist(b->pos);
    if (dist<a->radius+b->radius) {
        //compute normal
        Vec2 normal=(b->pos-a->pos);
        normal.normalize();
        //compute start
        Vec2 start=b->pos-normal*b->radius;
        //compute end
        Vec2 end=a->pos+normal*a->radius;
        //compute depth
        float depth=(start-end).length();
        Contact c = Contact(a,b,normal,start,end,depth);
        return c;
    } else {
        Contact c = Contact(a,b,Vec2(0,0),Vec2(0,0),Vec2(0,0),-1);
        return c;
    }

}

void Physics::ballResolution(const Contact& c) {
    if (c.depth<0) return;

    //move by depth
    c.a->pos-=c.normal*c.depth;
    c.b->pos+=c.normal*c.depth;

    //compute impulse
    float invMass=1.0f/c.a->mass+1.0f/c.b->mass;
    Vec2 vrel=c.a->vel-c.b->vel;
    float num=-(1+Physics::restitution)*vrel.dot(c.normal);
    float impulse=num/invMass;

    c.a->vel+=c.normal*(impulse/c.a->mass);
    c.b->vel-=c.normal*(impulse/c.b->mass);

}


Contact::Contact(std::shared_ptr<Ball> a, std::shared_ptr<Ball> b, Vec2 normal, Vec2 start, Vec2 end, float depth): a(a), b(b), normal(normal), start(start), end(end), depth(depth) {}