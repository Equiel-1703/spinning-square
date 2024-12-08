#include <iostream>

#include "WinUtils.hpp"
#include "Screen.hpp"
#include "Square.hpp"
#include "FrameLimiter.hpp"

#define PI 3.14159

int main(int argc, char const *argv[])
{
	WinUtils::setupConsole();
	WinUtils::hideCursor();
	CLEAR;

	Screen screen(100, 40);
	Square s(Vertice2D(34, 12), 14);
	FrameLimiter limiter(10); // 10 FPS

	// std::wcout << L"Before rotation:" << std::endl;
	// s.logVertices();
	
	for (int i = 0; i < 60; i++) {
		limiter.startFrame();

		s.rotate(PI / 12); // Rotate 15 degrees
		// std::wcout << L"After rotation:" << std::endl;
		// s.logVertices();

		screen.clearScreen();
		s.draw(screen);
		screen.showImage();

		limiter.endFrame(); // Limit the frame rate
	}

	std::wcout << std::endl << std::endl;
	PAUSE;
	
	WinUtils::showCursor();

	return 0;
}
