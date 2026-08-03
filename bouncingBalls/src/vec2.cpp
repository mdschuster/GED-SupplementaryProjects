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

Vec2 Vec2::operator+ (const Vec2& rhs) const {
    return {this->x+rhs.x, this->y+rhs.y};
}

Vec2 Vec2::operator- (const Vec2& rhs) const {
    return {this->x-rhs.x, this->y-rhs.y};
}
Vec2 Vec2::operator* (float value) const {
    return {this->x*value, this->y*value};
}

Vec2 operator* (float lhs, const Vec2& rhs) {
    return {rhs.x*lhs, rhs.y*lhs};
}

std::ostream& operator<< (std::ostream& os, const Vec2& rhs) {
    os<<"("<<rhs.x<<", "<<rhs.y<<")";
    return os;
}