#include "FrameLimiter.hpp"

FrameLimiter::FrameLimiter(int fps) : fps(fps), millisec_per_frame((int)round(1000 / fps)) {}

void FrameLimiter::delay(int millisecs)
{
	high_resolution_clock::time_point delay_count;
	high_resolution_clock::time_point delay_start = high_resolution_clock::now();

	do
	{
		delay_count = high_resolution_clock::now();
	} while (duration_cast<milliseconds>(delay_count - delay_start).count() < millisecs);
}

void FrameLimiter::startFrame()
{
	start = high_resolution_clock::now();
}

void FrameLimiter::endFrame()
{
	end = high_resolution_clock::now();

	int time_elapsed = duration_cast<milliseconds>(end - start).count();
	int remaining_time = millisec_per_frame - time_elapsed;

	if (remaining_time > 0)
		delay(remaining_time);
}