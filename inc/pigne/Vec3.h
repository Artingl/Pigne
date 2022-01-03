#pragma once

#include <pigne/Vec2.h>

typedef struct Vec3 {
    double x;
    double y;
    double z;

	Vec3(float _value) : x(_value), y(_value), z(_value) {};
	Vec3(float _x, Vec2 const& v) : x(_x), y(v.x), z(v.y) {};
	Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	Vec3 operator+(Vec3 const& other) { return Vec3(x + other.x, y + other.y, z + other.z); }
	Vec3 operator-(Vec3 const& other) { return Vec3(x - other.x, y - other.y, z - other.z); }
	Vec3 operator*(Vec3 const& other) { return Vec3(x * other.x, y * other.y, z * other.z); }
	Vec3 operator/(Vec3 const& other) { return Vec3(x / other.x, y / other.y, z / other.z); }
	Vec3 operator-() { return Vec3(-x, -y, -z); }

} Vec3;
