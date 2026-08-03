#include "vec2.hpp"
#include <cmath>

Vec2::Vec2(): x(0), y(0) {}

Vec2::Vec2(float x, float y): x(x), y(y) {}

float Vec2::length() const{
    return sqrtf(x * x + y * y);
}

float Vec2::dist(const Vec2& v) const{
    const Vec2 temp(v.x-this->x, v.y-this->y);
    return temp.length();
}

void Vec2::normalize() {
    const float len=this->length();
    x=x/len;
    y=y/len;
}

float Vec2::dot(const Vec2& v) const {
    return x*v.x+y*v.y;
}

bool Vec2::operator ==(const Vec2& rhs) const{
    return (rhs.x==x && rhs.y==y);
}
Vec2 Vec2::operator + (const Vec2& rhs) const{
    return Vec2(x+rhs.x,y+rhs.y);
}
Vec2 Vec2::operator * (float value) const{
    return Vec2(x*value,y*value);
}
void Vec2::operator +=(const Vec2& rhs){
    x+=rhs.x;
    y+=rhs.y;
}
Vec2 Vec2::operator -(const Vec2& rhs) const{
    return Vec2(x-rhs.x, y-rhs.y);
}
void Vec2::operator -=(const Vec2& rhs){
    x-=rhs.x;
    y-=rhs.y;
}
float Vec2::operator *(const Vec2& rhs) const{
    return x*rhs.x+y*rhs.y;
}
void Vec2::operator *=(const Vec2& rhs){
    x=x*rhs.x;
    y=y*rhs.y;
}

std::ostream& operator<< (std::ostream& os, const Vec2& rhs) {
    os<<"("<<rhs.x<<", "<<rhs.y<<")";
    return os;
}