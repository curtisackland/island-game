#include "Game.hpp"

Game::Game() : tilesPerWindowWidth(GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double()) {
    
    // State setup
    this->state = std::make_shared<GameState>();
    this->state->setup();
    

    // Player setup
    this->player = std::make_shared<Player>(this->state, 0);
    this->player->setScale((float) ((float) this->state->getMainView()->getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) this->state->getMainView()->getSize().x/50)/(float) this->player->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(25, 25); 
    this->eventSystem.addUpdateEntity(this->player);
    this->eventSystem.addDrawEntity(this->player, 0);
    
    // Map setup
    this->state->getMaps()->emplace_back(std::make_unique<IslandMap>());

    // Enemy
    this->enemies = this->spawnEnemiesOnMap(0);
}

Game::~Game() {
    printf("%ld\n", this->state.use_count());
    printf("%ld\n", this->player.use_count());
    printf("%ld\n", this->enemies->at(0).use_count());

    this->childrenReleaseReferences();
    this->eventSystem.releaseReferences();
    this->state->destroy();
    TextureFactory::destroy();
    GameConfig::destroy();

    printf("%ld\n", this->state.use_count());
    printf("%ld\n", this->player.use_count());
    printf("%ld\n", this->enemies->at(0).use_count());
}

void Game::childrenReleaseReferences() {
    this->player->releaseReferences();
    for (auto e : *this->enemies) {
        e->releaseReferences();
    }
}

void Game::gameLoop() {
    while (this->state->getMainWindow()->isOpen())
    {
        //printf("FPS: %f\n", 1.f/deltaTime);
        this->state->getTiming().resetTimer();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (this->state->getMainWindow()->pollEvent(event))
        {
            switch (event.type){
                //window closed
                case sf::Event::Closed:
                    this->state->getMainWindow()->close();
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
        this->state->getMainWindow()->clear(sf::Color::Black);

        this->drawMap(); //Draws visible tiles of the map
        
        this->eventSystem.notifyAll(); // Performs updates and draw calls
        
        this->state->getMainView()->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        this->state->getMainWindow()->setView(*this->state->getMainView());
        // end the current frame
        this->state->getMainWindow()->display();
    }
}

void Game::drawMap(){
    
    int left = (int) floor((this->player->getPosition().x - this->state->getMainView()->getSize().x/2)/this->state->getMainView()->getSize().x * this->tilesPerWindowWidth) - 1; //bounds of the map to be drawn
    int right = (int) floor((this->player->getPosition().x + this->state->getMainView()->getSize().x/2)/this->state->getMainView()->getSize().x * this->tilesPerWindowWidth) + 1;
    int top = (int) floor((this->player->getPosition().y - this->state->getMainView()->getSize().y/2)/this->state->getMainView()->getSize().x * this->tilesPerWindowWidth) - 1;
    int bottom = (int) floor((this->player->getPosition().y + this->state->getMainView()->getSize().y/2)/this->state->getMainView()->getSize().x * this->tilesPerWindowWidth) + 1;

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            this->state->getMainWindow()->draw(*this->state->getMaps()->at(this->state->getCurrentMap())->getTile(i, j));
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> Game::spawnEnemiesOnMap(const int layer) {
    std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> ret = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
    for(int i = 0; i < 1; i++){
        ret->push_back(std::make_shared<Enemy>(this->state, player, layer));
        ret->at(i)->setPosition(300, 300);
        ret->at(i)->setScale((float) ((float) this->state->getMainView()->getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) this->state->getMainView()->getSize().x/50)/(float) this->player->getTextureWidth());
        ret->at(i)->setOrigin(ret->at(i)->getLocalBounds().width/2, ret->at(i)->getLocalBounds().width/2);
        this->eventSystem.addUpdateEntity(ret->at(i));
        this->eventSystem.addDrawEntity(ret->at(i), 0);
    }
    return ret;
}
