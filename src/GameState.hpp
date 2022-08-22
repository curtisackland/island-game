#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.hpp"
/**
 * @brief Holds the current state of the game so other classes can use these variables to update their own states
 * 
 */
class GameState{
    private:
        static float deltaTime;
        static sf::Clock clock; // Game clock
        static std::vector<GameMap*> *maps; // Island map
        static int currentMap;
        static const int tileSize = 30;
    public:
        static GameState& getInstance();
        static float getDeltaTime();
        static std::vector<GameMap*>* getMaps() {return maps;}
        static int getCurrentMap(){return currentMap;}
        static void setCurrentMap(int layer);
        static void resetTimer();
};