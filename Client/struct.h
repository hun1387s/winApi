#pragma once


struct Vec2
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x * x + y * y);
	}
	Vec2& Normalize()
	{
		float fLen = Length();
		
		assert(0 != fLen); // zero vector

		x /= fLen;
		y /= fLen;
	
		return *this;
	}

public:
	Vec2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}
	Vec2 operator + (Vec2 vOther)
	{
		return Vec2(x + vOther.x,
					y + vOther.y);
	}
	Vec2 operator - (Vec2 vOther)
	{
		return Vec2(x - vOther.x,
					y - vOther.y);
	}
	Vec2 operator * (Vec2 vOther)
	{
		return Vec2(x * vOther.x,
					y * vOther.y);
	}
	Vec2 operator / (Vec2 vOther)
	{
		assert(! (0.f == vOther.x || 0.f == vOther.y) );
		return Vec2(x / vOther.x,
					y / vOther.y);
	}
public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{}
	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}
	Vec2(int _x, int _y)
		: x(float(_x))
		, y(float(_y))
	{}
	Vec2(POINT _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};