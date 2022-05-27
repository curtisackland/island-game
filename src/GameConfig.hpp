#pragma once
#include <boost/json.hpp>

class GameConfig {
    private:
        GameConfig();
        ~GameConfig();
        static GameConfig *self;

    public:
        static GameConfig& getInstance();

        // WIP
        static void forceRead();
        static void forceWrite();
        static void getProperty();
        static void setProperty();

};
