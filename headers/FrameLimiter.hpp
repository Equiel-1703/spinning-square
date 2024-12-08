#pragma once

#include <chrono>
#include <cmath>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

class FrameLimiter
{
private:
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point end;

	const int fps;
	const int millisec_per_frame;

	void delay(int millisecs);

public:
	FrameLimiter(int fps);

	void startFrame();
	void endFrame();
};