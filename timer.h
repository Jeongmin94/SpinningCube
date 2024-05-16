#pragma once

class Timer
{
public:
	Timer() : deltaTime(0.0f), now{} {
		QueryPerformanceFrequency(&clock);
		QueryPerformanceCounter(&last);
	}

	void update();
	float dt() const { return deltaTime; }

private:
	float deltaTime;
	LARGE_INTEGER clock;
	LARGE_INTEGER now, last;
};

