#pragma once
#include <math.h>
#include <stdio.h>
#include "Vector2.hpp"
#include "Noise2D.hpp"

class Noise2DPerlin : public Noise2D {
private:
    static int permutationArray[];
public:
    Noise2DPerlin(int seed, double frequency, double valueMin, double valueMax);
    ~Noise2DPerlin();
    double noise(double x, double y);
    int getPermutationArray(int index);

    static double lerp(double a, double b, double factor);
    static double fade(double t);
    static double grad(int hash, double x, double y, double z);
};
