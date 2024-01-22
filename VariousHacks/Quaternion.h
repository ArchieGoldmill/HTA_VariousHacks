#pragma once
#include "Game.h"

struct Quaternion
{
	float x;
	float y;
	float z;
	float w;

	void Lerp(const Quaternion* q1, const Quaternion* q2, float k2)
	{
		FUNC(0x0070AFC0, void, __thiscall, _Lerp, Quaternion*, const Quaternion*, const Quaternion*, float);
		_Lerp(this, q1, q2, k2);
	}

	void Slerp(const Quaternion* q1, const Quaternion* q2, float k2)
	{
		FUNC(0x005FED10, void, __fastcall, _Lerp, Quaternion*, const Quaternion*, const Quaternion*, float);
		_Lerp(this, q1, q2, k2);
	}

	void Zero()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
		this->w = 0.0;
	}

	void RotX(float radians)
	{
		long double v2; // st7

		v2 = radians * 0.5;
		this->y = 0.0;
		this->z = 0.0;
		this->x = sin(v2);
		this->w = cos(v2);
	}

	void RotY(float radians)
	{
		long double v2; // st7

		v2 = radians * 0.5;
		this->x = 0.0;
		this->z = 0.0;
		this->y = sin(v2);
		this->w = cos(v2);
	}

	void RotZ(float radians)
	{
		long double v2; // st7

		v2 = radians * 0.5;
		this->x = 0.0;
		this->y = 0.0;
		this->z = sin(v2);
		this->w = cos(v2);
	}
};