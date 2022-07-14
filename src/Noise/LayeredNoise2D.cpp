#include "LayeredNoise2D.hpp"


LayeredNoise2D::LayeredNoise2D(double noiseMin, double noiseMax) {
    this->noiseMin = noiseMin;
    this->noiseMax = noiseMax;
}

LayeredNoise2D::~LayeredNoise2D() {

}

void LayeredNoise2D::addLayer(std::shared_ptr<Noise2D> layer) {
    this->layerList.push_back(layer);
}

double LayeredNoise2D::noise(double x, double y) {
    double sum = 0;
    double sumMins = 0;
    double sumMaxs = 0;

    for (auto layer : this->layerList) {
        sum += layer->noise(x, y);
        sumMins += layer->getValueMin();
        sumMaxs += layer->getValueMax();
    }

    return (this->noiseMax - this->noiseMin) * ((sum - sumMins) / sumMaxs) + this->noiseMin;
}