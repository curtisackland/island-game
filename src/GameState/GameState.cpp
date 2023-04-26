#include "GameState.hpp"

GameState* GameState::instance = nullptr;

GameState::GameState() {

}

GameState::~GameState() {

}

GameState& GameState::getInstance() {
    if (instance) {
        return *instance;
    } else {
        instance = new GameState();
    }
}

void GameState::setup(unsigned int windowWidth, unsigned int windowHeight) {
    this->mainWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Island Game");
    this->mainView = std::make_unique<sf::View>();
    this->mainView->setSize(this->mainWindow->getSize().x, this->mainWindow->getSize().y);
    this->maps = std::make_unique<std::vector<std::unique_ptr<GameMap>>>();
}

void GameState::destroy() {
    this->maps.release();
    this->mainView.release();
    this->mainWindow.release();
    delete GameState::instance;
}
