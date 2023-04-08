#include "GameState.hpp"

void GameState::setup() {
    this->mainWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(1600, 900), "Island Game");
    this->mainView = std::make_unique<sf::View>();
    this->mainView->setSize(this->mainWindow->getSize().x, this->mainWindow->getSize().y);
    this->maps = std::make_unique<std::vector<std::unique_ptr<GameMap>>>();
}

void GameState::destroy() {
    this->maps.release();
    this->mainView.release();
    this->mainWindow.release();
}

void GameState::setCurrentMap(int layer){
    GameState::currentMap = layer;
}
