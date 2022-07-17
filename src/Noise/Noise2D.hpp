#pragma once

class Noise2D {
public:
    Noise2D();
    virtual ~Noise2D();
    virtual double noise(double x, double y) = 0;
};
