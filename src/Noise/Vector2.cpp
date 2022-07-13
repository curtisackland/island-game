#include "Vector2.hpp"

Vector2::Vector2(double x, double y) : x(x), y(y){

}

Vector2::~Vector2() {

}

Vector2 Vector2::operator+(Vector2& rhs) {
    return Vector2(this->x + rhs.x, this->y + rhs.y);
}

Vector2 Vector2::operator-(Vector2& rhs) {
    return Vector2(this->x + rhs.x, this->y + rhs.y);
}

double Vector2::dot(Vector2& rhs) {
    return this->x * rhs.x + this->y * rhs.y;
}

Vector2 Vector2::operator*(double& rhs) {
    return Vector2(this->x * rhs, this->y * rhs);
}
