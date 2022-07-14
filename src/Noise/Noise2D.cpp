#include "Noise2D.hpp"
#include <stdio.h>
Noise2D::Noise2D(int seed, double frequency, double valueMin, double valueMax) {
    this->setSeed(seed);
    this->setFrequency(frequency);
    this->setValueMin(valueMin);
    this->setValueMax(valueMax);
}

Noise2D::~Noise2D() {

}