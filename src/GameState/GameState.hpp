#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Timing.hpp"
#include "MapInfo.hpp"
#include "../Map/GameMap.hpp"
/**
 * @brief Holds the current state of the game so other classes can use these variables to update their own states
 * 
 */
class GameState{
private:

    std::unique_ptr<std::vector<std::unique_ptr<GameMap>>> maps; // Island map
    int currentMap;
    const int tileSize = 30;

    std::unique_ptr<sf::RenderWindow> mainWindow;
    std::unique_ptr<sf::View> mainView;

    Timing timing;
    std::unique_ptr<MapInfo> mapInfo;
public:
    GameState() = default;
    ~GameState() = default;
    void destroy();

    void setup();
    std::unique_ptr<std::vector<std::unique_ptr<GameMap>>>& getMaps() {return maps;}
    std::unique_ptr<sf::RenderWindow>& getMainWindow() {return this->mainWindow;}
    std::unique_ptr<sf::View>& getMainView() {return this->mainView;}
    std::unique_ptr<MapInfo>& getMapInfo() {return this->mapInfo;}

    Timing& getTiming() {return this->timing;}

    int getCurrentMap(){return currentMap;}
    void setCurrentMap(int layer);
};
