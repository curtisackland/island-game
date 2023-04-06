#pragma once
#include "../NoiseBuilder2D.hpp"
#include "Noise2DHighCenter.hpp"

class NoiseBuilder2DHighCenter : public NoiseBuilder2D {
private:
    double frequency;
    double amplitude;
    double bias;
    double xOffset;
    double yOffset;

public:
    NoiseBuilder2DHighCenter(double frequency, double amplitude, double bias, double xOffset, double yOffset);
    ~NoiseBuilder2DHighCenter() = default;
    Noise2D* create();
};
