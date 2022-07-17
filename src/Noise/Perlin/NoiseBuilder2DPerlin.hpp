#pragma once
#include "../NoiseBuilder2D.hpp"
#include "Noise2DPerlin.hpp"

class NoiseBuilder2DPerlin : public NoiseBuilder2D {
private:
    int seed;
    double frequency;
    double amplitude;
    double bias;
    double xOffset;
    double yOffset;
public:
    NoiseBuilder2DPerlin(int seed, double frequency);
    NoiseBuilder2DPerlin(int seed, double frequency, double amplitude);
    NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias);
    NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias, double xOffset, double yOffset);
    ~NoiseBuilder2DPerlin();
    Noise2D* create();
};