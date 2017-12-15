class Vector2{
	public:
		float x, y;

		/* constructors */
		Vector2();
		Vector2(float x, float y);

		float magnitude();
		float sqrmagnitude();
		Vector2 normalized();
		float dot(Vector2 b);

		Vector2 operator+(const Vector2& b);
		Vector2 operator-(const Vector2& b);
};