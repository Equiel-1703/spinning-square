#pragma once

class Vertice2D
{
public:
	double x, y;
	
	Vertice2D();
	Vertice2D(double x, double y);
	Vertice2D(const Vertice2D &v);

	// Operator overloading
	Vertice2D& operator=(const Vertice2D &v);
	Vertice2D& operator+=(const Vertice2D &v);
	Vertice2D& operator-=(const Vertice2D &v);
	Vertice2D operator+(const Vertice2D &v) const;
	Vertice2D operator-(const Vertice2D &v) const;
	
	int getIntX();
	int getIntY();

	void rotateAround(const Vertice2D &center, double rad_angle);
};