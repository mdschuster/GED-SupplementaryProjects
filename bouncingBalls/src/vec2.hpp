#pragma once
#include <iostream>

class Vec2 {
public:
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);

    float length() const;
    float dist(const Vec2& v) const;
    void normalize();
    float dot(const Vec2& v) const;

    bool operator ==(const Vec2& rhs) const;
    Vec2 operator + (const Vec2& rhs) const;
    Vec2 operator * (float value) const;
    Vec2 operator -(const Vec2& rhs) const;
    float operator *(const Vec2& rhs) const;
    void operator +=(const Vec2& rhs);
    void operator -=(const Vec2& rhs);
    void operator *=(const Vec2& rhs);
};

Vec2 operator* (float lhs, const Vec2& rhs);
std::ostream& operator<< (std::ostream& os, const Vec2& rhs);