#pragma once

typedef struct Vec2 {
    double x;
    double y;

	Vec2(float value) : x(value), y(value) {}
	Vec2(float _x, float _y) : x(_x), y(_y) {}

	Vec2 operator+(Vec2 const& other) { return Vec2(x + other.x, y + other.y); }
	Vec2 operator-(Vec2 const& other) { return Vec2(x - other.x, y - other.y); }
	Vec2 operator*(Vec2 const& other) { return Vec2(x * other.x, y * other.y); }
	Vec2 operator/(Vec2 const& other) { return Vec2(x / other.x, y / other.y); }

} Vec2;
