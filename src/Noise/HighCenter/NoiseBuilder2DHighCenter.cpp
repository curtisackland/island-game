#include "NoiseBuilder2DHighCenter.hpp"

NoiseBuilder2DHighCenter::NoiseBuilder2DHighCenter(double frequency, double amplitude, double bias, double xOffset, double yOffset) {
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->bias = bias;
    this->xOffset = xOffset;
    this->yOffset = yOffset;
}

Noise2D* NoiseBuilder2DHighCenter::create() {
    return new Noise2DHighCenter(this->frequency, this->amplitude, this->bias, this->xOffset, this->yOffset);
}
