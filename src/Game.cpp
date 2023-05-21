#include "Game.hpp"

Game::Game() : tilesPerWindowWidth(GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double()) {

    GameState::setup(1600, 900);

    // Player setup
    GameEntity::ID_TYPE playerID = PlayerFactory::createEntity(GameState::getInstance().getEntityManager(), 0);
    this->player = GameState::getInstance().getEntityManager().getEntity(playerID);
    this->player->setScale((float) ((float) GameState::getInstance().getMainView()->getSize().x/50)/(float) static_cast<Player*>(this->player.get())->getTextureWidth(), (float) ((float) GameState::getInstance().getMainView()->getSize().x/50)/(float) static_cast<Player*>(this->player.get())->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(25, 25); 
    GameState::getInstance().getEventManager().addUpdateEntity(this->player);
    GameState::getInstance().getEventManager().addDrawEntity(this->player, 0);
    
    // Map setup
    GameState::getInstance().getMaps()->emplace_back(std::make_unique<IslandMap>());

    // Enemy
    this->enemies = this->spawnEnemiesOnMap(0);
}

Game::~Game() {
    printf("%ld\n", this->player.use_count());
    for (auto& e : *this->enemies) {
        printf("%ld\n", e.use_count());
    }

    this->childrenReleaseReferences();
    //this->eventSystem.releaseReferences();
    GameState::destroyInstance();
    GameConfig::destroy();

    printf("%ld\n", this->player.use_count());
    for (auto& e : *this->enemies) {
        printf("%ld\n", e.use_count());
    }
}

void Game::childrenReleaseReferences() {
    this->player->releaseReferences();
    for (auto e : *this->enemies) {
        e->releaseReferences();
    }
}

void Game::gameLoop() {
    while (GameState::getInstance().getMainWindow()->isOpen())
    {
        //printf("FPS: %f\n", 1.f/deltaTime);
        GameState::getInstance().getTiming().resetTimer();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (GameState::getInstance().getMainWindow()->pollEvent(event))
        {
            switch (event.type){
                //window closed
                case sf::Event::Closed:
                    GameState::getInstance().getMainWindow()->close();
                    break;
                // key pressed
                case sf::Event::KeyPressed:
                    //printf("Player x: %f y: %f\n", this->player->getPosition().x, this->player->getPosition().y);
                default:
                    break;
            }
        }

        // Call all update functions on game objects

        // draw everything here...
        GameState::getInstance().getMainWindow()->clear(sf::Color::Black);

        this->drawMap(); //Draws visible tiles of the map
        
        GameState::getInstance().getEventManager().notifyAll(); // Performs updates and draw calls

        GameState::getInstance().getMainView()->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        GameState::getInstance().getMainWindow()->setView(*GameState::getInstance().getMainView());
        // end the current frame
        GameState::getInstance().getMainWindow()->display();
    }
}

void Game::drawMap(){
    
    int left = (int) floor((this->player->getPosition().x - GameState::getInstance().getMainView()->getSize().x/2)/GameState::getInstance().getMainView()->getSize().x * this->tilesPerWindowWidth) - 1; //bounds of the map to be drawn
    int right = (int) floor((this->player->getPosition().x + GameState::getInstance().getMainView()->getSize().x/2)/GameState::getInstance().getMainView()->getSize().x * this->tilesPerWindowWidth) + 1;
    int top = (int) floor((this->player->getPosition().y - GameState::getInstance().getMainView()->getSize().y/2)/GameState::getInstance().getMainView()->getSize().x * this->tilesPerWindowWidth) - 1;
    int bottom = (int) floor((this->player->getPosition().y + GameState::getInstance().getMainView()->getSize().y/2)/GameState::getInstance().getMainView()->getSize().x * this->tilesPerWindowWidth) + 1;

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            GameState::getInstance().getMainWindow()->draw(*GameState::getInstance().getMaps()->at(GameState::getInstance().getCurrentMapLayer())->getTile(i, j));
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> Game::spawnEnemiesOnMap(const int layer) {
    std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> ret = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
    const int numEnemies = 4;
    for(int i = 0; i < numEnemies; i++) {
        GameEntity::ID_TYPE id = EnemyFactory::createEntity(GameState::getInstance().getEntityManager(), this->player, layer);

        GameState::getInstance().getEntityManager().getEntity(id)->setPosition(800 * std::sin(2 * M_PI * ((float) i) / ((float)numEnemies)), 800 * std::cos(2 * M_PI * ((float) i) / ((float)numEnemies)));
        GameState::getInstance().getEntityManager().getEntity(id)->setScale((float) ((float) GameState::getInstance().getMainView()->getSize().x/50)/(float) static_cast<Player*>(this->player.get())->getTextureWidth(), (float) ((float) GameState::getInstance().getMainView()->getSize().x/50)/(float) static_cast<Player*>(this->player.get())->getTextureWidth());
        GameState::getInstance().getEntityManager().getEntity(id)->setOrigin(GameState::getInstance().getEntityManager().getEntity(id)->getLocalBounds().width/2, GameState::getInstance().getEntityManager().getEntity(id)->getLocalBounds().width/2);
        GameState::getInstance().getEventManager().addUpdateEntity(GameState::getInstance().getEntityManager().getEntity(id));
        GameState::getInstance().getEventManager().addDrawEntity(GameState::getInstance().getEntityManager().getEntity(id), 0);
    }
    return ret;
}
