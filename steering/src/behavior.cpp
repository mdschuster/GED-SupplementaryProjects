#include "behavior.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

Behavior::Behavior(){}

float Behavior::map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float Behavior::mapToRange (float rotation) {
    rotation = fmod(rotation, 2*M_PI);
    if (abs(rotation) > M_PI) {
        if (rotation < 0.0f)
            rotation += 2*M_PI;
        else
            rotation -= 2*M_PI;
    }
    return rotation;
}
