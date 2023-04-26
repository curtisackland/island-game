#include "Tile.hpp"
#include "../GameState/GameState.hpp"

#define RESOURCES_IMAGES_GRASS 0
#define RESOURCES_IMAGES_GRASS_PATH "resources/images/grass.png"
#define RESOURCES_IMAGES_STONE 1
#define RESOURCES_IMAGES_STONE_PATH "resources/images/stone.png"

// TODO: switch how tile size is calculated
#define TILE_SIZE_CONSTRUCTOR 1600 / GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double()

Tile::Tile(int xIndex, int yIndex) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setDefinedTexture(-1);
    this->setPosition(xIndex * this->tileSize, yIndex * this->tileSize);
}

Tile::Tile(float x, float y) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setDefinedTexture(-1);
    this->setPosition(x, y);
}

Tile::Tile(int id, float x, float y) : sf::Sprite(), tileSize(TILE_SIZE_CONSTRUCTOR) {
    this->setDefinedTexture(id);
    this->setPosition(x, y);
}

void Tile::setDefinedTexture(int textureNumber) {
    std::string tile = "";
    switch(textureNumber){
        case -1:
            this->walkable = true;
            tile = "no-texture.png";
            break;
        case 0:
            this->walkable = true;
            tile = "testgrass.png";
            break;
        case 1:
            this->walkable = false;
            tile = "stone.png";
            break;
        case 2:
            this->walkable = false;
            tile = "water.png";
            break;
        case 3:
            this->walkable = true;
            tile = "sand.png";
            break;
        default:
            std::string err = "Tile number invalid \"" + std::to_string(textureNumber) + "\"";
            throw new std::out_of_range(err.c_str());
            break;
    }
    this->setTexture(*(GameState::getInstance().getTextureFactory().getTexture("resources/images/" + tile)), true);
    this->setScale((TILE_SIZE_CONSTRUCTOR) / (GameState::getInstance().getTextureFactory().getTexture("resources/images/" + tile)->getSize().x), (TILE_SIZE_CONSTRUCTOR)/(GameState::getInstance().getTextureFactory().getTexture("resources/images/" + tile)->getSize().y));
}

int Tile::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

bool Tile::isWalkable(){
    return this->walkable;
}

Tile::~Tile(){}
