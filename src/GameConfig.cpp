#include "GameConfig.hpp"

GameConfig* GameConfig::self = nullptr;

GameConfig::GameConfig() {
    this->configFiles = new std::unordered_map<boost::json::string, boost::json::object>;
}

GameConfig::~GameConfig() {
    delete this->configFiles;
    this->configFiles = nullptr;
}

boost::json::object const & GameConfig::getJson(boost::json::string fileName) {
    auto result = this->configFiles->find(fileName);
    if (result != this->configFiles->end()) {
        return result->second;
    } else {
        this->addFile(fileName);
        return getJson(fileName);
    }
}

void GameConfig::addFile(boost::json::string fileName) {
    // Read file
    std::ifstream inFile;
    inFile.open(fileName.c_str());

    if (inFile.fail()) {
        throw std::ifstream::failure("File is empty or does not exist");
    }

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    
    if (str.empty()) {
        throw std::domain_error("Json file must contain an object");
    }
    
    // Parse json
    boost::json::value val = boost::json::parse(str);
    

    if (!val.is_object()) {
        throw std::domain_error("Json file must contain an object");
    }

    // Copy the json and convert it to an object so it can be indexed with at(key)
    boost::json::object *json = new boost::json::object(val.as_object());
    (*this->configFiles)[fileName] = *json;
    inFile.close();
}

GameConfig& GameConfig::getInstance() {
    if (self == nullptr) {
        self = new GameConfig();
    }

    return *self;
}

void GameConfig::forceRead() {
    for (auto configFile: *(this->configFiles)) {
        addFile(configFile.first);
    }
}
/*
boost::json::value const & GameConfig::getProperty(boost::json::string fileName) {
    return this->configFiles;
}
*/

void GameConfig::destroy() {
    delete GameConfig::self;
    GameConfig::self = nullptr;
}