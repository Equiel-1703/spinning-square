#include <iostream>
#include "Screen.hpp"
#include "Square.hpp"
#include "WinUtils.hpp"

int main(int argc, char const *argv[])
{
	WinUtils::setupConsole();
	CLEAR;

	Screen screen(100, 40);
	Square s(Vertice2D(0, 0), 10);

	s.draw(screen);

	screen.showImage();

	std::wcout << std::endl << std::endl;
	PAUSE;

	return 0;
}
