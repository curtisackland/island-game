#pragma once
#include <vector>
#include <memory>
#include "Noise2D.hpp"
class LayeredNoise2D {
private:
    std::vector<std::shared_ptr<Noise2D>> layerList;
    double noiseMin;
    double noiseMax;
public:
    LayeredNoise2D(double noiseMin, double noiseMax);
    ~LayeredNoise2D();
    void addLayer(std::shared_ptr<Noise2D> layer);
    double noise(double x, double y);
};