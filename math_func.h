#pragma once
#include "struct.h"

// 180 : PI = x : theta(rad)
const float PI = 3.141592f;
float toRad(float deg);

// rotation
// https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions
vec3 rotationAboutX(const vec3& v, float degree);
vec3 rotationAboutY(const vec3& v, float degree);
vec3 rotationAboutZ(const vec3& v, float degree);