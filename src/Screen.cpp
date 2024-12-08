#include "WinUtils.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>

#include "Screen.hpp"

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

void Screen::showImage()
{
	WinUtils::displayImage(image, WIDTH, HEIGHT);
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

void Screen::drawLine(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	int steps = max(abs(deltaX), abs(deltaY));

	double incX = (double)deltaX / (double)steps;
	double incY = (double)deltaY / (double)steps;

	double xk, yk;

	for (int i = 0; i < steps; i++)
	{
		xk = (double)x1 + (incX * i);
		yk = (double)y1 + (incY * i);

		turnOnPixel(round(xk), round(yk));
	}
}