#pragma once

class Noise2D {
public:
    Noise2D() = default;
    virtual ~Noise2D() = default;
    virtual double noise(double x, double y) const = 0;
};
