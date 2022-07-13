#pragma once
#include <math.h>
#include "Vector2.hpp"
#include "Noise2D.hpp"

class Noise2DPerlin : Noise2D {
public:
    double noise(double x, double y);
};
