#pragma once

#include "WinAPIConfig.hpp"

/**
 * @class Screen
 * @brief Class that represents the screen of the program
 */

class Screen
{
private:
	static constexpr TCHAR PIXEL_ON = L'#'; /** The  character that represents a pixel turned on in the screen */
	static constexpr TCHAR PIXEL_OFF = L' '; /** The character that represents a pixel turned off in the screen */
	const int WIDTH, HEIGHT; /** The dimension of the screen */

	TCHAR *image = nullptr; /** A matrix that represents the screen */

	bool isOutOfScreen(int x, int y); /** Check if a pixel is out of the screen */

	void hideCursor(); /** Hide the cursor carret in the screen */
	void showCursor(); /** Show the cursor carret in the screen */

public:
	Screen(int width, int height); /** Constructor */
	~Screen();

	void clearScreen(); /** Clear the screen (turn off all pixels) */
	void turnOnPixel(int x, int y); /** Turn on a pixel in the screen */
	void turnOffPixel(int x, int y); /** Turn off a pixel in the screen */
	void showImage(); /** Show the image in the screen */
};