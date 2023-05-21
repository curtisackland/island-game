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
