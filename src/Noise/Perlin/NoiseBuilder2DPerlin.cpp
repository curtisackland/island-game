#include "NoiseBuilder2DPerlin.hpp"

NoiseBuilder2DPerlin::NoiseBuilder2DPerlin(int seed, double frequency, double amplitude, double bias) {
    this->seed = seed;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->bias = bias;
}

NoiseBuilder2DPerlin::~NoiseBuilder2DPerlin() {

}

Noise2D* NoiseBuilder2DPerlin::create() {
    return new Noise2DPerlin(this->seed, this->frequency, this->amplitude, this->bias);
}
