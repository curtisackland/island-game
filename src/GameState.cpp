#include "GameState.hpp"

int GameState::currentMap = 0;
std::vector<GameMap*> *GameState::maps = new std::vector<GameMap*>;
float GameState::deltaTime = 0;
sf::Clock GameState::clock;

GameState::GameState(){

}

float GameState::getDeltaTime(){
    return GameState::deltaTime;
}

void GameState::resetTimer(){
    GameState::deltaTime = GameState::clock.restart().asSeconds();
}

void GameState::setCurrentMap(int layer){
    GameState::currentMap = layer;
}

void GameState::destroy() {
    for (auto map : *GameState::maps) {
        delete map;
        map = nullptr;
    }
    delete GameState::maps;
    GameState::maps = nullptr;
}
