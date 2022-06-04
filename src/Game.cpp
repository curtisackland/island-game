#include "Game.hpp"

Game::Game() {
    
    // Window setup
    MainWindow::getInstance();

    //Player setup
    this->player = new Player(0);
    this->player->setScale((float) ((float) MainWindow::getInstance().getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) MainWindow::getInstance().getSize().x/50)/(float) this->player->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(25, 25);
    this->eventSystem.addUpdateEntity(this->player);
    
    // Map setup
    GameState::getMaps()->push_back(new IslandMap());
    GameState::getMaps()->at(GameState::getCurrentMap())->generate(50, 50);

    // View setup
    this->view = new sf::View();
    this->view->setSize(MainWindow::getInstance().getSize().x, MainWindow::getInstance().getSize().y);

    this->enemies = this->spawnEnemiesOnMap(0);
    this->eventSystem.addUpdateEntity(this->enemies->at(0));
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
        this->eventSystem.notifyAll();

        // draw everything here...
        MainWindow::getInstance().clear(sf::Color::Black);

        this->drawMap(); //Draws visible tiles of the map
        
        MainWindow::getInstance().draw(*(this->player));
        MainWindow::getInstance().draw(*(this->enemies->at(0)));
        
        this->view->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        MainWindow::getInstance().setView(*this->view);
        // end the current frame
        MainWindow::getInstance().display();
    }
}

void Game::drawMap(){
    int left = (int) floor((this->player->getPosition().x - MainWindow::getInstance().getSize().x/2)/MainWindow::getInstance().getSize().x * this->tileSize) - 1; //bounds of the map to be drawn
    int right = (int) floor((this->player->getPosition().x + MainWindow::getInstance().getSize().x/2)/MainWindow::getInstance().getSize().x * this->tileSize) + 1;
    int top = (int) floor((this->player->getPosition().y - MainWindow::getInstance().getSize().y/2)/MainWindow::getInstance().getSize().x * this->tileSize) - 1;
    int bottom = (int) floor((this->player->getPosition().y + MainWindow::getInstance().getSize().y/2)/MainWindow::getInstance().getSize().x * this->tileSize) + 1;
    if(left < 0){
        left = 0;
    }
    if(right > GameState::getMaps()->at(GameState::getCurrentMap())->getWidth()){
        right = GameState::getMaps()->at(GameState::getCurrentMap())->getWidth();
    }
    if(top < 0){
        top = 0;
    }
    if(bottom > GameState::getMaps()->at(GameState::getCurrentMap())->getHeight()){
        bottom = GameState::getMaps()->at(GameState::getCurrentMap())->getHeight();
    }

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            MainWindow::getInstance().draw(*GameState::getMaps()->at(GameState::getCurrentMap())->getTile(i, j));
        }
    }
}

std::vector<Enemy*> * Game::spawnEnemiesOnMap(int layer) {
    std::vector<Enemy*>* ret = new std::vector<Enemy*>;
    ret->push_back(new Enemy(player, layer));
    ret->at(0)->setPosition(300, 300);
    ret->at(0)->setScale((float) ((float) MainWindow::getInstance().getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) MainWindow::getInstance().getSize().x/50)/(float) this->player->getTextureWidth());
    return ret;
}