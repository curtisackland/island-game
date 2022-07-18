#pragma once
#include <math.h>
#include <stdio.h>
#include "../Noise2D.hpp"

class Noise2DPerlin : public Noise2D {
private:
    static int permutationArray[];
    int seed;
    double frequency;
    double amplitude;
    double bias;
    double xOffset;
    double yOffset;
public:

    Noise2DPerlin(int seed, double frequency, double amplitude, double bias, double xOffset, double yOffset);
    ~Noise2DPerlin();
    double noise(double x, double y);
    inline int getPermutationArray(int index);

    inline static double lerp(double a, double b, double factor);
    inline static double fade(double t);
    static double grad(int hash, double x, double y, double z);

    inline int getSeed() const {return this->seed;}
    inline void setSeed(int const seed) {this->seed = seed;}

    inline double getFrequency() const {return this->frequency;}
    inline void setFrequency(double const frequency) {this->frequency = frequency;}
    
    inline double getAmplitude() const {return this->amplitude;}
    inline void setAmplitude(double const amplitude) {this->amplitude = amplitude;}

    inline double getBias() const {return this->bias;}
    inline void setBias(double const bias) {this->bias = bias;}

    inline double getXOffset() const {return this->xOffset;}
    inline void setXOffset(double const xOffset) {this->xOffset = xOffset;}

    inline double getYOffset() const {return this->yOffset;}
    inline void setYOffset(double const yOffset) {this->yOffset = yOffset;}
};
