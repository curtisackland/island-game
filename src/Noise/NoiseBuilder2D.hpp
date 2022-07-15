#pragma once
#include "Noise2D.hpp"

class NoiseBuilder2D {
public:
    virtual Noise2D* create() = 0;
};
