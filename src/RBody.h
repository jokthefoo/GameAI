#pragma once
#include "ofMath.h"

struct Vector2
{
	float x;
	float y;

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2 operator + (Vector2 const other)
	{
		Vector2 res;
		res.x = x + other.x;
		res.y = y + other.y;
		return res;
	}
	Vector2 operator - (Vector2 const other)
	{
		Vector2 res;
		res.x = x - other.x;
		res.y = y - other.y;
		return res;
	}
	Vector2 operator * (float const other)
	{
		Vector2 res;
		res.x = x * other;
		res.y = y * other;
		return res;
	}
	Vector2 operator *= (float const other)
	{
		x *= other;
		y *= other;
		return *this;
	}
	Vector2 operator += (Vector2 const other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2 operator -= (Vector2 const other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vector2 operator /= (float const other)
	{
		x /= other;
		y /= other;
		return *this;
	}
	float Mag ()
	{
		return sqrt(x * x + y * y);
	}
	void Normalize()
	{
		float mag = this->Mag();
		if (mag == 0)
		{
			x = 0;
			y = 0;
			return;
		}
		x /= mag;
		y /= mag;
	}
};

struct Steering
{
	Vector2 linear;
	float angular;
};

struct RigidBody
{
	Vector2 pos;
	float orien;
	Vector2 vel;
	float rot;

	RigidBody()
	{
		orien = 0;
		rot = 0;
	}
};
