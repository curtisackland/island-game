#include "MapInfo.hpp"

MapInfo::MapInfo(double tileSize) {
    this->tileSize = tileSize;
}

double MapInfo::getTileSize() {
    return this->tileSize;
}

void MapInfo::setTileSize(double tileSize) {
    this->tileSize = tileSize;
}
