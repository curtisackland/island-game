#include "NoiseBuilder2DPerlin.hpp"

NoiseBuilder2DPerlin::NoiseBuilder2DPerlin(int seed, double frequency) {
    this->seed = seed;
    this->frequency = frequency;
    this->amplitude = 0;
    this->bias = 0;
    this->xOffset = 0;
    this->yOffset = 0;
}

NoiseBuilder2DPerlin::NoiseBuilder2DPerlin(int seed, double frequency, double amplitude) {
    this->seed = seed;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->bias = 0;
    this->xOffset = 0;
    this->yOffset = 0;
}

NoiseBuilder2DPerlin::NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias) {
    this->seed = seed;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->bias = bias;
    this->xOffset = 0;
    this->yOffset = 0;
}

NoiseBuilder2DPerlin::NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias, double xOffset, double yOffset) {
    this->seed = seed;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->bias = bias;
    this->xOffset = xOffset;
    this->yOffset = yOffset;
}

NoiseBuilder2DPerlin::~NoiseBuilder2DPerlin() {

}

Noise2D* NoiseBuilder2DPerlin::create() {
    return new Noise2DPerlin(this->seed, this->frequency, this->amplitude, this->bias, this->xOffset, this->yOffset);
}
