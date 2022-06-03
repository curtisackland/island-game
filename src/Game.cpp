#include "Game.hpp"

Game::Game() {
    
    // Window setup
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "My Game");

    //Player setup
    this->player = new Player();
    this->player->setScale((float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(25, 25);
    
    // Map setup
    this->maps.push_back(new IslandMap());
    this->maps.at(0)->generate(50, 50, this->window);

    // View setup
    this->view = new sf::View();
    this->view->setSize(this->window->getSize().x, this->window->getSize().y);

    this->enemies = this->spawnEnemiesOnMap(0);
}

void Game::gameLoop() {
    float speed = 300;
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type){

                //window closed
                case sf::Event::Closed:
                    window->close();
                    break;
                
                // key pressed
                case sf::Event::KeyPressed:
                    //printf("Player x: %f y: %f\n", this->player->getPosition().x, this->player->getPosition().y);
                default:
                    break;
            }
        }

        this->deltaTime = this->clock.restart().asSeconds();

        //printf("FPS: %f\n", 1.f/deltaTime);

        // clear the window with black color
        window->clear(sf::Color::Black);


        speed = 300;
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) 
        || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
            speed = speed*this->diagonalScalar;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            int x = (int) floor((this->player->getPosition().x-speed*deltaTime - this->player->getGlobalBounds().width/2)/this->window->getSize().x * this->tileSize);
            int y1 = (int) floor((this->player->getPosition().y + this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int y2 = (int) floor((this->player->getPosition().y - this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);

            if((this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x, y1)->isWalkable())
                || (this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x, y2)->isWalkable())){

            }else {
                this->player->move(-speed*deltaTime, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            int x = (int) floor((this->player->getPosition().x + speed*deltaTime + this->player->getGlobalBounds().width/2)/this->window->getSize().x * this->tileSize);
            int y1 = (int) floor((this->player->getPosition().y + this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int y2 = (int) floor((this->player->getPosition().y - this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);

            if((this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x, y1)->isWalkable())
                || (this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x, y2)->isWalkable())){

            } else {
                this->player->move(speed*deltaTime, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            int x1 = (int) floor((this->player->getPosition().x + this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int x2 = (int) floor((this->player->getPosition().x - this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y - speed*deltaTime - this->player->getGlobalBounds().height/2)/this->window->getSize().x * this->tileSize);

            if((this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x1, y)->isWalkable())
                || (this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x2, y)->isWalkable())){
            } else {
                this->player->move(0, -speed*deltaTime);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            int x1 = (int) floor((this->player->getPosition().x + this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int x2 = (int) floor((this->player->getPosition().x - this->player->getGlobalBounds().width/4)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y + speed*deltaTime + this->player->getGlobalBounds().height/2)/this->window->getSize().x * this->tileSize);

            if((this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x1, y)->isWalkable())
                || (this->player->getGlobalBounds().intersects(this->maps.at(this->player->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
                && !this->maps.at(this->player->getMapLayer())->getTile(x2, y)->isWalkable())){
            } else {
                this->player->move(0, speed*deltaTime);
            }
        }

        // draw everything here...

        this->view->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        this->window->setView(*this->view);

        this->drawMap(); //Draws visible tiles of the map
        
        float rot = 180 - atan2(sf::Mouse::getPosition(*this->window).x - (float) this->window->getSize().x/2, sf::Mouse::getPosition(*this->window).y - (float) this->window->getSize().y/2) * (180/M_PI);
        this->player->setRotation(rot);
        
        this->window->draw(*(this->player));
        this->window->draw(*(this->enemies->at(0)));
        // end the current frame
        this->window->display();
    }
}

void Game::drawMap(){
    int left = (int) floor((this->player->getPosition().x - this->window->getSize().x/2)/this->window->getSize().x * this->tileSize) - 1; //bounds of the map to be drawn
    int right = (int) floor((this->player->getPosition().x + this->window->getSize().x/2)/this->window->getSize().x * this->tileSize) + 1;
    int top = (int) floor((this->player->getPosition().y - this->window->getSize().y/2)/this->window->getSize().x * this->tileSize) - 1;
    int bottom = (int) floor((this->player->getPosition().y + this->window->getSize().y/2)/this->window->getSize().x * this->tileSize) + 1;
    if(left < 0){
        left = 0;
    }
    if(right > this->maps.at(this->player->getMapLayer())->getWidth()){
        right = this->maps.at(this->player->getMapLayer())->getWidth();
    }
    if(top < 0){
        top = 0;
    }
    if(bottom > this->maps.at(this->player->getMapLayer())->getHeight()){
        bottom = this->maps.at(this->player->getMapLayer())->getHeight();
    }

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            this->window->draw(*(this->maps.at(this->player->getMapLayer())->getTile(i, j)));
        }
    }
}

std::vector<Enemy*> * Game::spawnEnemiesOnMap(int layer) {
    std::vector<Enemy*>* ret = new std::vector<Enemy*>;
    ret->push_back(new Enemy(layer));
    ret->at(0)->setPosition(300, 300);
    ret->at(0)->setScale((float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth());
    return ret;
}