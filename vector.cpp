
Vector2::Vector2()
{
	x = 0, y = 0;
}

Vector2(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

float magnitude();
float sqrmagnitude();
Vector2 normalized();
float dot(Vector2 b);

Vector2 operator+(const Vector2& b);
Vector2 operator-(const Vector2& b);