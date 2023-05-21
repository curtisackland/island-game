#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameEvents.hpp"
#include "EntityManager.hpp"
#include "Timing.hpp"
#include "MapInfo.hpp"
#include "TextureFactory.hpp"
#include "Map/GameMap.hpp"
/**
 * @brief Holds the current state of the game so other classes can use these variables to update their own states
 * 
 */
class GameState{
private:
    static GameState* instance;
    std::unique_ptr<std::vector<std::unique_ptr<GameMap>>> maps; // Island map
    int currentMap;
    const int tileSize = 30;

    std::unique_ptr<sf::RenderWindow> mainWindow;
    std::unique_ptr<sf::View> mainView;
    std::unique_ptr<MapInfo> mapInfo;

    GameEvents eventManager;
    EntityManager entityManager;
    Timing timing;
    TextureFactory textureFactory;
    GameState() = default;
    ~GameState() = default;
public:
    static GameState& getInstance();
    static void setup(unsigned int windowWidth, unsigned int windowHeight);
    static void destroyInstance();

    std::unique_ptr<std::vector<std::unique_ptr<GameMap>>>& getMaps() {return maps;}

    std::unique_ptr<sf::RenderWindow>& getMainWindow() {return this->mainWindow;}
    std::unique_ptr<sf::View>& getMainView() {return this->mainView;}
    std::unique_ptr<MapInfo>& getMapInfo() {return this->mapInfo;}

    GameEvents& getEventManager() {return this->eventManager;}
    EntityManager& getEntityManager() {return this->entityManager;}
    Timing& getTiming() {return this->timing;}
    TextureFactory& getTextureFactory() {return this->textureFactory;}


    int getCurrentMapLayer() {return GameState::currentMap;}
    void setCurrentMapLayer(int layer) {GameState::currentMap = layer;}
};
