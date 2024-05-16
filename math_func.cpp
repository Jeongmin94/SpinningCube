#pragma once
#include "pch.h"
#include "math_func.h"

float toRad(float deg) { return (PI / 180.0f) * deg; }

vec3 rotationAboutX(const vec3& v, float degree)
{
	float rad = toRad(degree);
	return vec3(
		v.x,
		cos(rad) * v.y - sin(rad) * v.z,
		sin(rad) * v.y + cos(rad) * v.z);
}

vec3 rotationAboutY(const vec3& v, float degree)
{
	float rad = toRad(degree);
	return vec3(
		cos(rad) * v.x + sin(rad) * v.z,
		v.y,
		-sin(rad) * v.x + cos(rad) * v.z);
}

vec3 rotationAboutZ(const vec3& v, float degree)
{
	float rad = toRad(degree);
	return vec3(
		cos(rad) * v.x - sin(rad) * v.y,
		sin(rad) * v.x + cos(rad) * v.y,
		v.z);
}