#include "timer.h"

void Timer::update()
{
    now = SDL_GetPerformanceCounter();

    deltaTime = (now - last) / (double)SDL_GetPerformanceFrequency();

    last = now;
}