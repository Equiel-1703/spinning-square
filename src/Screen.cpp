#include "../headers/WinUtils.hpp"

#include <algorithm>
#include <iostream>

#include "../headers/Screen.hpp"

Screen::Screen(int width, int height) : WIDTH(width), HEIGHT(height)
{
	image = new TCHAR[WIDTH * HEIGHT];
	clearScreen();
}

Screen::~Screen()
{
	delete[] image;
}

void Screen::clearScreen()
{
	std::fill(image, image + (WIDTH * HEIGHT), PIXEL_OFF);
}

bool Screen::isOutOfScreen(int x, int y)
{
	return x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT;
}

void Screen::turnOnPixel(int x, int y)
{
	if (isOutOfScreen(x, y))
		return;
	
	image[y * WIDTH + x] = PIXEL_ON;
}

void Screen::turnOffPixel(int x, int y)
{
	if (isOutOfScreen(x, y))
		return;
	
	image[y * WIDTH + x] = PIXEL_OFF;
}

void Screen::showImage()
{
	WinUtils::hideCursor();
	WinUtils::displayImage(image, WIDTH, HEIGHT);
	WinUtils::showCursor();
}