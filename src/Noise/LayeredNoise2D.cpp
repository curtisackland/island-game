#include "LayeredNoise2D.hpp"


void LayeredNoise2D::addLayer(std::unique_ptr<Noise2D> layer) {
    this->layerList.push_back(std::move(layer));
}

double LayeredNoise2D::noise(double x, double y) const {
    double sum = 0;
    for (auto const & layer : this->layerList) {
        sum += layer->noise(x, y);
    }

    return sum;
}
