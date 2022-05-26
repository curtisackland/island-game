#pragma once


class GameConfig {
    private:
        GameConfig();
        ~GameConfig();
        static GameConfig *self;

    public:
        static GameConfig& getInstance();


};
