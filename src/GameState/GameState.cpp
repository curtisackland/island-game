#include "GameState.hpp"

GameState* GameState::instance = nullptr;

GameState& GameState::getInstance() {
    if (!GameState::instance) {
        throw std::runtime_error("GameState instance has not been initialized");
    }
    return *GameState::instance;
}

void GameState::setup(unsigned int windowWidth, unsigned int windowHeight) {
    if (GameState::instance) { // Delete instance if it already exists
        destroyInstance();
        GameState::instance = nullptr;
    }

    GameState::instance = new GameState();
    getInstance(); // Create new instance

    instance->mainWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Island Game");
    instance->mainView = std::make_unique<sf::View>();
    instance->mainView->setSize(instance->mainWindow->getSize().x, instance->mainWindow->getSize().y);
    instance->maps = std::make_unique<std::vector<std::unique_ptr<GameMap>>>();
}

void GameState::destroyInstance() {
    delete GameState::instance;
}
