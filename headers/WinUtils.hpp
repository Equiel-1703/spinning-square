#pragma once

#include "WinAPIConfig.hpp"

#define CLEAR system("cls")
#define PAUSE system("pause")

namespace WinUtils
{
	void setupConsole();
	void changeCursorPosition(int x, int y);
	void hideCursor();
	void showCursor();
	void displayImage(TCHAR *image, int width, int height);
} // namespace WindowsUtils