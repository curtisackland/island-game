#include "GameConfig.hpp"
#include "error.h"
#include <fstream>
#include <string>

GameConfig* GameConfig::self = nullptr;

GameConfig::GameConfig() {
    this->configFiles = new std::unordered_map<boost::json::string, boost::json::object>;
}

GameConfig::~GameConfig() {
    delete this->configFiles;
}

boost::json::object const & GameConfig::getJson(boost::json::string fileName) const {
    auto result = this->configFiles->find(fileName);
    if (result != this->configFiles->end()) {
        return result->second;
    } else {
        throw std::out_of_range("Tried to access config file which is not loaded");
    }
}

void GameConfig::addFile(boost::json::string fileName) {
    // Read file
    std::ifstream inFile;
    inFile.open(fileName.c_str());

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    
    // Parse json
    boost::json::value val = boost::json::parse(str);
    
    assert(val.is_object());

    // Copy the json and convert it to an object so it can be indexed with at(key)
    boost::json::object *json = new boost::json::object(val.as_object());
    this->configFiles->insert({fileName, *json});
    
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