#pragma once

template <typename T>
struct PointBase
{
	T x;
	T y;
};

struct CVector
{
	float x;
	float y;
	float z;
	CVector operator-(const CVector& rhs)
	{
		return { x - rhs.x, y - rhs.y, z - rhs.z };
	}
	double operator*(const CVector& rhs)
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}
};