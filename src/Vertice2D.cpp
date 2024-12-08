#include <cmath>

#include "Vertice2D.hpp"

Vertice2D::Vertice2D() : x(0), y(0) {}

Vertice2D::Vertice2D(double x, double y) : x(x), y(y) {}

Vertice2D::Vertice2D(const Vertice2D &v) : x(v.x), y(v.y) {}

Vertice2D& Vertice2D::operator=(const Vertice2D &v)
{
	x = v.x;
	y = v.y;

	return *this;
}

Vertice2D& Vertice2D::operator+=(const Vertice2D &v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vertice2D& Vertice2D::operator-=(const Vertice2D &v)
{
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}

Vertice2D Vertice2D::operator+(const Vertice2D &v) const
{
	return Vertice2D(x + v.x, y + v.y);
}

Vertice2D Vertice2D::operator-(const Vertice2D &v) const
{
	return Vertice2D(x - v.x, y - v.y);
}

int Vertice2D::getIntX()
{
	return (int)round(x);
}

int Vertice2D::getIntY()
{
	return (int)round(y);
}

void Vertice2D::rotateAround(const Vertice2D &center, double rad_angle)
{
	// Translate the vertice to the origin of the 'center' vertice
	x -= center.x;
	y -= center.y;

	// Rotating the vertice
	double new_x = x * cos(rad_angle) - y * sin(rad_angle);
	double new_y = x * sin(rad_angle) + y * cos(rad_angle);

	// Translate the vertice back to the original position
	x = new_x + center.x;
	y = new_y + center.y;
}