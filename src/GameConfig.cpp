#include "GameConfig.hpp"

GameConfig* GameConfig::self = nullptr;

GameConfig::GameConfig() {

}

GameConfig::~GameConfig() {

}

GameConfig& GameConfig::getInstance() {
    if (self == nullptr) {
        self = new GameConfig();
    }

    return *self;
}
