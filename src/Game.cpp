#include "Game.hpp"

Game::Game() : tilesPerWindowWidth(GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double()) {
    
    // Window setup
    MainWindow::getInstance();

    // View setup
    MainView::getInstance().setSize(MainWindow::getInstance().getSize().x, MainWindow::getInstance().getSize().y);

    // Player setup
    this->player = std::make_shared<Player>(0);
    this->player->setScale((float) ((float) MainView::getInstance().getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) MainView::getInstance().getSize().x/50)/(float) this->player->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(25, 25); 
    this->eventSystem.addUpdateEntity(this->player);
    this->eventSystem.addDrawEntity(this->player, 0);
    
    // Map setup
    GameState::getMaps()->push_back(new IslandMap());

    // Enemy
    this->enemies = this->spawnEnemiesOnMap(0);
}

Game::~Game() {
    delete this->view;

    MainWindow::destroy();
    MainView::destroy();
    GameState::destroy();
    TextureFactory::destroy();
    GameConfig::destroy();
}

void Game::gameLoop() {
    while (MainWindow::getInstance().isOpen())
    {
        //printf("FPS: %f\n", 1.f/deltaTime);
        GameState::resetTimer();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (MainWindow::getInstance().pollEvent(event))
        {
            switch (event.type){
                //window closed
                case sf::Event::Closed:
                    MainWindow::getInstance().close();
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
        MainWindow::getInstance().clear(sf::Color::Black);

        this->drawMap(); //Draws visible tiles of the map
        
        this->eventSystem.notifyAll(); // Performs updates and draw calls
        
        MainView::getInstance().setCenter(this->player->getPosition().x, this->player->getPosition().y);
        MainWindow::getInstance().setView(MainView::getInstance());
        // end the current frame
        MainWindow::getInstance().display();
    }
}

void Game::drawMap(){
    
    int left = (int) floor((this->player->getPosition().x - MainView::getInstance().getSize().x/2)/MainView::getInstance().getSize().x * this->tilesPerWindowWidth) - 1; //bounds of the map to be drawn
    int right = (int) floor((this->player->getPosition().x + MainView::getInstance().getSize().x/2)/MainView::getInstance().getSize().x * this->tilesPerWindowWidth) + 1;
    int top = (int) floor((this->player->getPosition().y - MainView::getInstance().getSize().y/2)/MainView::getInstance().getSize().x * this->tilesPerWindowWidth) - 1;
    int bottom = (int) floor((this->player->getPosition().y + MainView::getInstance().getSize().y/2)/MainView::getInstance().getSize().x * this->tilesPerWindowWidth) + 1;

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            MainWindow::getInstance().draw(*GameState::getMaps()->at(GameState::getCurrentMap())->getTile(i, j));
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> Game::spawnEnemiesOnMap(const int layer) {
    std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> ret = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
    for(int i = 0; i < 1; i++){
        new Enemy(player, layer);
        ret->emplace_back(std::make_shared<Enemy>(player, layer));
        ret->at(i)->setPosition(300, 300);
        ret->at(i)->setScale((float) ((float) MainView::getInstance().getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) MainView::getInstance().getSize().x/50)/(float) this->player->getTextureWidth());
        ret->at(i)->setOrigin(ret->at(i)->getLocalBounds().width/2, ret->at(i)->getLocalBounds().width/2);
        this->eventSystem.addUpdateEntity(ret->at(i));
        this->eventSystem.addDrawEntity(ret->at(i), 0);
    }
    return ret;
}
