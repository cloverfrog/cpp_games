#ifndef CORE_TYPES_H
#define CORE_TYPES_H

#include <cmath>

namespace PlantsVs {
struct Vector2 {
    float x, y;

    Vector2() = default;
    ~Vector2() = default;
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    void operator+=(const Vector2& other) { x += other.x; y += other.y; }
    Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    void operator-=(const Vector2& other) { x -= other.x; y -= other.y; }
    float operator*(const Vector2& other) const { return x * other.x + y * other.y; }
    Vector2 operator*(float scalar) const { return Vector2(x * scalar, y * scalar); }
    void operator*=(float scalar) { x *= scalar; y *= scalar; }

    float Length() const { return std::sqrt(x * x + y * y); }
    Vector2 Normalize() const { 
        float length = Length();
        if (length == 0) return Vector2(0, 0);
        return Vector2(x / length, y / length);
    }
};
}

#endif // CORE_TYPES_H