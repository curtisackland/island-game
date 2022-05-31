#pragma once
#include <boost/json.hpp>
#include <unordered_map>
//#include <boost/json/src.hpp> // research what this does more

class GameConfig {
    private:
        GameConfig();
        ~GameConfig();
        static GameConfig *self;
        std::unordered_map<boost::json::string, boost::json::object> *configFiles;

    public:
        static GameConfig& getInstance();
        boost::json::object const & getJson(boost::json::string const) const;
        void addFile(boost::json::string);
        void forceRead();

        // WIP
        void forceWrite();

};
