#pragma once
#include "pch.h"

class Timer
{
public:
    Timer() : last(SDL_GetPerformanceCounter()), now(0.0){};

public:
    void update();
    const float dt() { return deltaTime; }

private:
    float deltaTime = 0.0f;
    Uint64 last;
    Uint64 now;
};