#pragma once

#include "Vertice2D.hpp"
#include "Screen.hpp"

class Square
{
private:
	Vertice2D TL, TR, BL, BR; // Top-Left, Top-Right, Bottom-Left, Bottom-Right
	Vertice2D center;		  // Center of the square
public:
	Square(Vertice2D from, int size);

	void draw(Screen &screen);

	void rotate(double rad_angle);
	void move(Vertice2D &new_TL);

	void logVertices();
};