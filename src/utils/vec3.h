#pragma once

struct vec3
{
    float x, y, z;

    vec3() : x(0.0f), y(0.0f), z(0.0f){};
    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};
    vec3(const vec3 &v) : x(v.x), y(v.y), z(v.z){};

    vec3 &operator=(const vec3 &v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        return *this;
    }
};