#pragma once
#ifndef CLASS_VEC3
#define CLASS_VEC3

#include <cmath>
#include <cstdlib>
#include <cstdio>

template <class T>

class vec3
{

public:

	T x, y, z;

	//Constructors


	vec3() {}


	vec3(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {}


	vec3(const vec3 &vec) : x(vec.x), y(vec.y), z(vec.z) {}

	//Destructor


	~vec3() {}

	//Methods


	void normalize()
	{
		T modulus = sqrt(x*x + y*y + z*z);
		this->x = x / modulus;
		this->y = y / modulus;
		this->z = z / modulus;
	}


	void zero()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}


	bool is_zero() const
	{
		if (this->x == 0 && this->y == 0 && this->z == 0)
			return true;
		else
			return false;
	}


	T distance_to(const vec3 &vec) const
	{
		return(sqrt((vec.x - x)*(vec.x - x) + (vec.y - y)(vec.y - y) + (vec.z - z)));
	}

	//Operators


	vec3<T> operator+(const vec3 & val)
	{

		return vec3<T>(x + val.x, y + val.y, z + val.z);
	}


	vec3<T> operator-(const vec3 & val)
	{
		return vec3<T>(x - val.x, y - val.y, z - val.z);
	}


	bool operator==(const vec3 & val) const
	{
		if (x == val.x && y == val.y && z == val.z)
			return true;
	}


	vec3<T> operator+=(const vec3 & val)
	{
		return vec3(x += val, y += val, z += val);
	}


	vec3<T> operator-=(const vec3 & val)
	{
		return vec3(x -= val, y -= val, z -= val);
	}


	vec3<T> operator=(const vec3& val)
	{
		return vec3(x = val.x, y = val.y, z = val.z);
	}
};

#endif // !CLASS_VEC3

