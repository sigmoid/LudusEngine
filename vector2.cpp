#include <cmath>
#include "vector2.h"

Vector2::Vector2()
{
	x = 0, y = 0;
}

Vector2::Vector2(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

float Vector2::magnitude()
{
	return sqrt(x*x + y*y);
}

float Vector2::sqrmagnitude()
{
	return x*x + y*y;
}

Vector2 Vector2::normalized()
{
	float mag = magnitude();
	
	Vector2 norm(x/mag, y/mag);
	return norm;
}

float Vector2::dot(Vector2 b)
{
	return x * b.x + y * b.y;
}

Vector2 Vector2::operator+(const Vector2& b)
{
	Vector2 res;

	res.x = x + b.x;
	res.y = y + b.y;

	return res;
}

Vector2 Vector2::operator-(const Vector2& b)
{
	Vector2 res;

	res.x = x - b.x;
	res.y = y - b.y;

	return res;
}