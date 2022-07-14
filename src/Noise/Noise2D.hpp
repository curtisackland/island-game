#pragma once

class Noise2D {
private:
    int seed;
    double frequency;
    double valueMin;
    double valueMax;
public:
    Noise2D(int seed, double frequency, double valueMin, double valueMax);
    ~Noise2D();
    virtual double noise(double x, double y) = 0;

    double getSeed() {return this->seed;}
    void setSeed(int newSeed) {this->seed = newSeed;}

    double getValueMin() {return this->valueMin;}
    void setValueMin(double newValueMin) {this->valueMin = newValueMin;}

    double getValueMax() {return this->valueMax;}
    void setValueMax(double newValueMax) {this->valueMax = newValueMax;}

    double getFrequency() {return this->frequency;}
    void setFrequency(double newFrequency) {this->frequency = newFrequency;}
};
