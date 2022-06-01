#include "Tile.hpp"

Tile::Tile(int id, float x, float y) : sf::Sprite(){
    std::string tile = "";
    switch(id){
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
    this->setPosition(x, y);
}

int Tile::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

bool Tile::isWalkable(){
    return this->walkable;
}

Tile::~Tile(){}