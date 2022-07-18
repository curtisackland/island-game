#include "Noise2DHighCenter.hpp"

Noise2DHighCenter::Noise2DHighCenter(double frequency, double amplitude, double bias, double xOffset, double yOffset) {
    this->setFrequency(frequency);
    this->setAmplitude(amplitude);
    this->setBias(bias);
    this->setXOffset(xOffset);
    this->setYOffset(yOffset);
}

Noise2DHighCenter::~Noise2DHighCenter() {

}

double Noise2DHighCenter::noise(double x, double y) {
    x = x + xOffset;
    y = y + yOffset;
    double dist = sqrt(x * x + y * y);
    return this->amplitude / (1 + pow(M_E, (dist * this->frequency - 5))) + this->bias;
}