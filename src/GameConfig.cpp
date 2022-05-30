#include "GameConfig.hpp"
#include "error.h"
#include <fstream>
#include <string>

GameConfig* GameConfig::self = nullptr;

GameConfig::GameConfig() {
    this->configFiles = new std::unordered_map<boost::json::string, boost::json::value*>;
}

GameConfig::~GameConfig() {
    delete this->configFiles;
}

boost::json::value const * GameConfig::getJson(boost::json::string fileName) const {
    auto result = this->configFiles->find(fileName);
    if (result != this->configFiles->end()) {
        return result->second;
    } else {
        throw std::out_of_range("Tried to access config file which is not loaded");
    }
}

void GameConfig::addFile(boost::json::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName.c_str());

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();

    boost::json::value* json = new boost::json::value;
    *json = boost::json::parse(str);
    this->configFiles->insert({fileName, json});
}

GameConfig& GameConfig::getInstance() {
    if (self == nullptr) {
        self = new GameConfig();
    }

    return *self;
}

void GameConfig::forceRead() {
    for (auto& configFile: *(this->configFiles)) {
        addFile(configFile.first);
    }
}
/*
boost::json::value const & GameConfig::getProperty(boost::json::string fileName) {
    return this->configFiles;
}
*/