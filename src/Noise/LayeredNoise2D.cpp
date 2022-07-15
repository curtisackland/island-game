#include "LayeredNoise2D.hpp"


LayeredNoise2D::LayeredNoise2D() {

}

LayeredNoise2D::~LayeredNoise2D() {
    for (auto layer : this->layerList) {
        delete layer;
    }
}

void LayeredNoise2D::addLayer(NoiseBuilder2D *layer) {
    this->layerList.push_back(layer->create());
}

double LayeredNoise2D::noise(double x, double y) {
    double sum = 0;
    for (auto layer : this->layerList) {
        sum += layer->noise(x, y);
    }

    return sum;
}