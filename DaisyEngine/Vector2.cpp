#include "Vector2.h"

namespace Daisy
{
	Vector2::Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 Vector2::operator*(const Vector2& v)
	{
		return Vector2(x * v.x, y * v.y);
	}
	Vector2 Vector2::operator/(const Vector2& v)
	{
		return Vector2(x / v.x, y / v.y);
	}
	Vector2 Vector2::operator+(const Vector2& v)
	{
		return Vector2(x + v.x, y + v.y);
	}
	Vector2 Vector2::operator-(const Vector2& v)
	{
		return Vector2(x - v.x, y - v.y);
	}
}
