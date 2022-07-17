#pragma once
#include <vector>
#include <memory>
#include "Noise2D.hpp"
#include "NoiseBuilder2D.hpp"
class LayeredNoise2D {
private:
    std::vector<Noise2D*> layerList;
public:
    LayeredNoise2D();
    ~LayeredNoise2D();
    void addLayer(NoiseBuilder2D *layer);
    double noise(double x, double y);
};
