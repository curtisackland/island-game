#include "IslandMap.hpp"
IslandMap::IslandMap() : GameMap(){
    
}

IslandMap::~IslandMap() {
    
}

void IslandMap::generate(int width, int height, sf::RenderWindow *window){
    int isStone = false;
    for(int i = 0; i < width; i++){
        this->map->push_back(new std::vector<Tile*>);
        for(int j = 0; j < height; j++){
            isStone = std::rand() % 15;
            if(isStone == 0){
                (*this->map)[i]->push_back(new Tile(1, (float) i * (float) window->getSize().x/this->tileSize, (float) j * (float) window->getSize().x/this->tileSize));
            } else {
                (*this->map)[i]->push_back(new Tile(0, (float) i * (float) window->getSize().x/this->tileSize, (float) j * (float) window->getSize().x/this->tileSize));
            }
            (*(*this->map)[i])[j]->setScale(((float) window->getSize().x/this->tileSize)/(float) (*(*this->map)[i])[j]->getTextureWidth(), ((float) window->getSize().x/this->tileSize)/(float) (*(*this->map)[i])[j]->getTextureWidth());
        }
    }
}