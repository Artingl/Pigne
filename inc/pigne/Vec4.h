#pragma once

#include <pigne/Vec3.h>

typedef struct Vec4 {
    double x;
    double y;
    double z;
    double w;

	Vec4(float _value) : x(_value), y(_value), z(_value), w(_value) {};
	Vec4(float _x, Vec3 const& v) : x(_x), y(v.x), z(v.y), w(v.z) {};
	Vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {};

	Vec4 operator+(Vec4 const& other) { return Vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
	Vec4 operator-(Vec4 const& other) { return Vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
	Vec4 operator*(Vec4 const& other) { return Vec4(x * other.x, y * other.y, z * other.z, w * other.w); }
	Vec4 operator/(Vec4 const& other) { return Vec4(x / other.x, y / other.y, z / other.z, w / other.w); }
	Vec4 operator-() { return Vec4(-x, -y, -z, -w); }

} Vec4;
