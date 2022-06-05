#include "Tile.hpp"

#define RESOURCES_IMAGES_GRASS 0
#define RESOURCES_IMAGES_GRASS_PATH "resources/images/grass.png"
#define RESOURCES_IMAGES_STONE 1
#define RESOURCES_IMAGES_STONE_PATH "resources/images/stone.png"

#define TILE_SIZE_CONSTRUCTOR MainView::getInstance().getSize().x / GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double()

Tile::Tile(int xIndex, int yIndex) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setPosition(xIndex * this->tileSize, yIndex * this->tileSize);
}

Tile::Tile(float x, float y) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setPosition(x, y);
}

Tile::Tile(int id, float x, float y) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setDefinedTexture(id);
    this->setPosition(x, y);
}

void Tile::setDefinedTexture(int textureNumber) {
    std::string tile = "";
    switch(textureNumber){
        case 0:
            this->walkable = true;
            tile = "grass.png";
            break;
        case 1:
            this->walkable = false;
            tile = "stone.png";
            break;
        default:
            break;
    }
    this->setTexture(*(TextureFactory::getTexture("resources/images/" + tile)));
}

int Tile::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

bool Tile::isWalkable(){
    return this->walkable;
}

Tile::~Tile(){}