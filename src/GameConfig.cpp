#include "GameConfig.hpp"

GameConfig* GameConfig::self = nullptr;

GameConfig::GameConfig() {
    this->configFiles = new std::unordered_map<boost::json::string, boost::json::object*>;
}

GameConfig::~GameConfig() {
    delete this->configFiles;
}

boost::json::object const * GameConfig::getJsonObject(boost::json::string fileName) const {
    auto result = this->configFiles->find(fileName);
    if (result != this->configFiles->end()) {
        return result->second;
    } else {
        throw fileName;
    }
}

void GameConfig::addFile(boost::json::string fileName) {
    
    this->configFiles->insert({fileName, new boost::json::object});
}

GameConfig& GameConfig::getInstance() {
    if (self == nullptr) {
        self = new GameConfig();
    }

    return *self;
}

void forceRead() {

}
