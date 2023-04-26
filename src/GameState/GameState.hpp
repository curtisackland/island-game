#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "EntityManager.hpp"
#include "Timing.hpp"
#include "MapInfo.hpp"
#include "TextureFactory.hpp"
#include "../Map/GameMap.hpp"
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

    EntityManager entityManager;
    Timing timing;
    TextureFactory textureFactory;
    GameState();
    ~GameState();
public:
    static GameState& getInstance();
    void setup(unsigned int windowWidth, unsigned int windowHeight);
    void destroy();

    inline std::unique_ptr<std::vector<std::unique_ptr<GameMap>>>& getMaps() {return maps;}

    inline std::unique_ptr<sf::RenderWindow>& getMainWindow() {return this->mainWindow;}
    inline std::unique_ptr<sf::View>& getMainView() {return this->mainView;}
    inline std::unique_ptr<MapInfo>& getMapInfo() {return this->mapInfo;}

    inline EntityManager& getEntityManager() {return this->entityManager;}
    inline Timing& getTiming() {return this->timing;}
    inline TextureFactory& getTextureFactory() {return this->textureFactory;}


    inline int getCurrentMapLayer() {return GameState::currentMap;}
    inline void setCurrentMapLayer(int layer) {GameState::currentMap = layer;}
};
