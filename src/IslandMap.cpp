#include "IslandMap.hpp"
IslandMap::IslandMap() : GameMap(){
    
}

IslandMap::~IslandMap() {
    
}

void IslandMap::generate(int width, int height){
    int isStone = false;
    for(int i = 0; i < width; i++){
        this->map->push_back(new std::vector<Tile*>);
        for(int j = 0; j < height; j++){
            isStone = std::rand() % 15;
            if(isStone == 0){
                (*this->map)[i]->push_back(new Tile(1, (float) i * (float) MainWindow::getInstance().getSize().x/this->tileSize, (float) j * (float) MainWindow::getInstance().getSize().x/this->tileSize));
            } else {
                (*this->map)[i]->push_back(new Tile(0, (float) i * (float) MainWindow::getInstance().getSize().x/this->tileSize, (float) j * (float) MainWindow::getInstance().getSize().x/this->tileSize));
            }
            (*(*this->map)[i])[j]->setScale(((float) MainWindow::getInstance().getSize().x/this->tileSize)/(float) (*(*this->map)[i])[j]->getTextureWidth(), ((float) MainWindow::getInstance().getSize().x/this->tileSize)/(float) (*(*this->map)[i])[j]->getTextureWidth());
        }
    }
}