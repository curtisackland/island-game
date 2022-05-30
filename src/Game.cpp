#include "Game.hpp"

Game::Game(){
    // Window setup
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "My Game");

    //Player setup
    this->player = new Player();
    this->player->setScale((float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth(), (float) ((float) this->window->getSize().x/50)/(float) this->player->getTextureWidth());
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    this->player->setPosition(50, 50);
    
    // Map setup
    this->island = new IslandMap();
    this->island->generate(100, 100, this->window);

    // View setup
    this->view = new sf::View();
    this->view->setCenter(this->player->getPosition().x, this->player->getPosition().y);
    this->view->setSize(this->window->getSize().x, this->window->getSize().y);
}

void Game::gameLoop(){
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

        //TODO When colliding, move as far as possible towards the object
        //TODO Check all corners for collision not just the center
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            int x = (int) floor((this->player->getPosition().x-speed*deltaTime - this->player->getLocalBounds().width/2)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y)/this->window->getSize().x * this->tileSize);

            if(this->player->getGlobalBounds().intersects(this->island->getTile(x, y)->getGlobalBounds()) 
                && !this->island->getTile(x, y)->isWalkable()){
                printf("worked!\n");
            } else {
                this->player->setPosition(this->player->getPosition().x - speed*deltaTime, this->player->getPosition().y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            int x = (int) floor((this->player->getPosition().x + speed*deltaTime + this->player->getLocalBounds().width/2)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y)/this->window->getSize().x * this->tileSize);

            if(this->player->getGlobalBounds().intersects(this->island->getTile(x, y)->getGlobalBounds()) 
                && !this->island->getTile(x, y)->isWalkable()){
                printf("worked!\n");
            } else {
                this->player->setPosition(this->player->getPosition().x + speed*deltaTime, this->player->getPosition().y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            int x = (int) floor((this->player->getPosition().x)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y - speed*deltaTime - this->player->getLocalBounds().height/2)/this->window->getSize().x * this->tileSize);

            if(this->player->getGlobalBounds().intersects(this->island->getTile(x, y)->getGlobalBounds()) 
                && !this->island->getTile(x, y)->isWalkable()){
                printf("worked!\n");
            } else {
                this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y - speed*deltaTime);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            int x = (int) floor((this->player->getPosition().x)/this->window->getSize().x * this->tileSize);
            int y = (int) floor((this->player->getPosition().y + speed*deltaTime + this->player->getLocalBounds().height/2)/this->window->getSize().x * this->tileSize);

            if(this->player->getGlobalBounds().intersects(this->island->getTile(x, y)->getGlobalBounds()) 
                && !this->island->getTile(x, y)->isWalkable()){
                printf("worked!\n");
            } else {
                this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y + speed*deltaTime);
            }
        }

        // draw everything here...

        this->view->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        this->window->setView(*this->view);

        this->drawMap(); //Draws visible tiles of the map
        
        float rot = 180 - atan2(sf::Mouse::getPosition(*this->window).x - (float) this->window->getSize().x/2, sf::Mouse::getPosition(*this->window).y - (float) this->window->getSize().y/2) * (180/M_PI);
        this->player->setRotation(rot);
        
        this->window->draw(*(this->player));
        
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
    if(right > this->island->getWidth()){
        right = this->island->getWidth();
    }
    if(top < 0){
        top = 0;
    }
    if(bottom > this->island->getHeight()){
        bottom = this->island->getHeight();
    }

    for(int i = left; i < right; i++){
        for(int j = top; j < bottom; j++){
            this->window->draw(*(this->island->getTile(i, j)));
        }
    }
}
