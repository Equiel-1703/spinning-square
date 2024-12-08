#include <iostream>

#include "WinUtils.hpp"

namespace WinUtils
{
	void setupConsole()
	{
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleTitle(L"Spinning Square");
	}

	void changeCursorPosition(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void hideCursor()
	{
		CONSOLE_CURSOR_INFO cursor_info;

		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		cursor_info.bVisible = FALSE;
		
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	}

	void showCursor()
	{
		CONSOLE_CURSOR_INFO cursor_info;

		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
		cursor_info.bVisible = TRUE;

		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	}

	void displayImage(TCHAR *image, int width, int height)
	{
		for (int i = 0; i < height; i++) 
		{
			changeCursorPosition(0, i);
			WriteConsole(
				GetStdHandle(STD_OUTPUT_HANDLE),
				image + width * i,
				width,
				NULL, NULL);
		}
	}
} // namespace WinUtils