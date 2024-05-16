#include "pch.h"
#include "Timer.h"

void Timer::update()
{
	QueryPerformanceCounter(&now);

	deltaTime = (now.QuadPart - last.QuadPart) / float(clock.QuadPart);

	last = now;
}
