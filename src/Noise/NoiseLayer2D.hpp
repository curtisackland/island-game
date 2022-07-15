#pragma once
#include "Noise2D.hpp"

class NoiseLayer2D {
private:
    double amplitude;
    double frequency;
public:
    Noise2D *noiseAlgorithm;
    NoiseLayer2D();
    ~NoiseLayer2D();

    double noise(double x, double y);

    inline void setAmplitude(double amplitude) {this->amplitude = amplitude;}
    inline double getAmplitude() {return this->amplitude;}

    inline void setFrequency(double frequency) {this->frequency = frequency;}
    inline double getFrequency() {return this->frequency;}
};
