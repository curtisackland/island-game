#pragma once

class Vector2 {
public:
    double x, y;
    Vector2(double x, double y);
    ~Vector2();
    Vector2 operator+(Vector2& rhs);
    Vector2 operator-(Vector2& rhs);
    double dot(Vector2& rhs);
    Vector2 operator*(double& rhs);
};
