#pragma once
#include <math.h>
#include <stdio.h>
#include "../Noise2D.hpp"

class Noise2DPerlin : public Noise2D {
private:
    static const int permutationArray[];
    int seed;
    double frequency;
    double amplitude;
    double bias;
    double xOffset;
    double yOffset;
public:

    Noise2DPerlin(int seed, double frequency, double amplitude, double bias, double xOffset, double yOffset);
    ~Noise2DPerlin();
    double noise(double x, double y) const;
    int getPermutationArray(int index) const;

    static double lerp(double a, double b, double factor);
    static double fade(double t);
    static double grad(int hash, double x, double y, double z);

    int getSeed() const {return this->seed;}
    void setSeed(int const seed) {this->seed = seed;}

    double getFrequency() const {return this->frequency;}
    void setFrequency(double const frequency) {this->frequency = frequency;}
    
    double getAmplitude() const {return this->amplitude;}
    void setAmplitude(double const amplitude) {this->amplitude = amplitude;}

    double getBias() const {return this->bias;}
    void setBias(double const bias) {this->bias = bias;}

    double getXOffset() const {return this->xOffset;}
    void setXOffset(double const xOffset) {this->xOffset = xOffset;}

    double getYOffset() const {return this->yOffset;}
    void setYOffset(double const yOffset) {this->yOffset = yOffset;}
};
