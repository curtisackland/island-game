#pragma once
#include <math.h>
#include <stdio.h>
#include "../Noise2D.hpp"

class Noise2DHighCenter : public Noise2D {
private:
    static const int permutationArray[];
    double frequency;
    double amplitude;
    double bias;
    double xOffset;
    double yOffset;
public:

    Noise2DHighCenter(double frequency, double amplitude, double bias, double xOffset, double yOffset);
    ~Noise2DHighCenter() = default;
    double noise(double x, double y) const;
    
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
