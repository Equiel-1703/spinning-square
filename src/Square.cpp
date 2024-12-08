#include <stdexcept>
#include <iostream>

#include "Square.hpp"

Square::Square(Vertice2D from, int size)
{
	if (size <= 0)
		throw std::invalid_argument("The size of the square must be greater than 0.");

	size -= 1; // Size is considering the first pixel so we need to subtract it

	TL = from;
	TR = Vertice2D(from.x + size, from.y);
	BL = Vertice2D(from.x, from.y + size);
	BR = Vertice2D(from.x + size, from.y + size);

	center = Vertice2D((TL.x + BR.x) / 2, (TL.y + BR.y) / 2);
}

void Square::draw(Screen &screen)
{
	screen.drawLine(TL.getIntX(), TL.getIntY(), TR.getIntX(), TR.getIntY());
	screen.drawLine(TR.getIntX(), TR.getIntY(), BR.getIntX(), BR.getIntY());
	screen.drawLine(BR.getIntX(), BR.getIntY(), BL.getIntX(), BL.getIntY());
	screen.drawLine(BL.getIntX(), BL.getIntY(), TL.getIntX(), TL.getIntY());
}

void Square::rotate(double rad_angle)
{
	TL.rotateAround(center, rad_angle);
	TR.rotateAround(center, rad_angle);
	BL.rotateAround(center, rad_angle);
	BR.rotateAround(center, rad_angle);
}

void Square::move(Vertice2D &new_TL)
{
	Vertice2D diff = new_TL + TL;

	TL += diff;
	TR += diff;
	BL += diff;
	BR += diff;

	center += diff;
}

void Square::logVertices()
{
	std::wcout << L"TL: (" << TL.x << L", " << TL.y << L")" << std::endl;
	std::wcout << L"TR: (" << TR.x << L", " << TR.y << L")" << std::endl;
	std::wcout << L"BL: (" << BL.x << L", " << BL.y << L")" << std::endl;
	std::wcout << L"BR: (" << BR.x << L", " << BR.y << L")" << std::endl;
}