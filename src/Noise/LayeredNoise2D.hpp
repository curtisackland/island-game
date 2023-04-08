#pragma once
#include <vector>
#include <memory>
#include "Noise2D.hpp"

class LayeredNoise2D {
private:
    std::vector<std::unique_ptr<Noise2D>> layerList;
public:
    LayeredNoise2D() = default;
    ~LayeredNoise2D() = default;
    void addLayer(std::unique_ptr<Noise2D> layer);
    double noise(double x, double y) const;
};
