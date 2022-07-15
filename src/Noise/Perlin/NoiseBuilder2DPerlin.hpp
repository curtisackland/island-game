#pragma once
#include "../NoiseBuilder2D.hpp"
#include "Noise2DPerlin.hpp"

class NoiseBuilder2DPerlin : public NoiseBuilder2D {
private:
    int seed;
    double frequency;
    double amplitude;
    double bias;
public:
    NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias);
    ~NoiseBuilder2DPerlin();
    Noise2D* create();
};