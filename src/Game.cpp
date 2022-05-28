#include "Game.hpp"

Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "My Game");
    this->player = new sf::Sprite();
    //this->player->setOrigin(this->player->getSize().x/2, this->player->getSize().y/2);
    //this->player->setOutlineColor(sf::Color::Black);
    //this->player->setOutlineThickness(2.f);
    this->playerTexture = new sf::Texture();
    this->playerTexture->loadFromFile("player.png");
    this->player->setTexture(*this->playerTexture);
    this->player->setScale((float) ((float) this->window->getSize().x/50)/(float) this->playerTexture->getSize().x, (float) ((float) this->window->getSize().x/50)/(float) this->playerTexture->getSize().x);
    this->player->setOrigin(this->player->getLocalBounds().width/2, this->player->getLocalBounds().width/2);
    
    this->terrain = new sf::Texture();
    this->terrain->loadFromFile("grass.png");

    this->block = new sf::Texture();
    this->block->loadFromFile("block.png");

    this->map = new int*[50];
    this->mapShape = new sf::Sprite**[50];
    for(int i = 0; i < 50; i++){
        this->map[i] = new int[50];
        this->mapShape[i] = new sf::Sprite*[50];
        for(int j = 0; j < 50; j++){
            this->mapShape[i][j] = new sf::Sprite();
            this->mapShape[i][j]->setPosition((float) i * (float) window->getSize().x/this->tileSize, (float) j * (float) window->getSize().x/this->tileSize);
            int r = std::rand() % 15;
            if(r == 0){
                map[i][j] = 1;
                this->mapShape[i][j]->setTexture(*this->block);
                this->mapShape[i][j]->setScale((float) ((float) this->window->getSize().x/this->tileSize)/(float) this->block->getSize().x, (float) ((float) this->window->getSize().x/this->tileSize)/(float) this->block->getSize().x); //scaling to make sprites be proper size
            } else {
                map[i][j] = 0;
                this->mapShape[i][j]->setTexture(*this->terrain);
                this->mapShape[i][j]->setScale((float) ((float) this->window->getSize().x/this->tileSize)/(float) this->terrain->getSize().x, (float) ((float) this->window->getSize().x/this->tileSize)/(float) this->terrain->getSize().x); //scaling to make sprites be proper size
            }
        }
    }
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // left key is pressed: move our character
            /*
            if(this->player->getGlobalBounds().intersects(
                this->mapShape[(int) floor((this->player->getPosition().x-speed*deltaTime)/this->window->getSize().x * this->tileSize)]
                [(int) floor((this->player->getPosition().y)/this->window->getSize().x * this->tileSize)]->getGlobalBounds())
                && this->map[(int) floor((this->player->getPosition().x-speed*deltaTime)/this->window->getSize().x * this->tileSize) - 1]
                [(int) floor((this->player->getPosition().y)/this->window->getSize().x * this->tileSize)] == 1){
                printf("worked!\n");
            } else {
                this->player->setPosition(this->player->getPosition().x - speed*deltaTime, this->player->getPosition().y);
            }
            */
           this->player->setPosition(this->player->getPosition().x - speed*deltaTime, this->player->getPosition().y);
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            // left key is pressed: move our character
            this->player->setPosition(this->player->getPosition().x + speed*deltaTime, this->player->getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            // left key is pressed: move our character
            this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y - speed*deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            // left key is pressed: move our character
            this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y + speed*deltaTime);
        }

        
        // draw everything here...
        // window.draw(...);

        this->view->setCenter(this->player->getPosition().x, this->player->getPosition().y);
        this->window->setView(*this->view);


        float temp = this->clock.getElapsedTime().asSeconds();
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 17; j++){
                this->window->draw(*this->mapShape[i][j]);
                
                if(map[i][j] == 1){
                    if(this->player->getGlobalBounds().intersects(this->mapShape[i][j]->getGlobalBounds())){
                        //printf("collision!\n");
                        //return;
                    }
                }
                
            }
        }
        
        float rot = 180 - atan2(sf::Mouse::getPosition(*this->window).x - (float) this->window->getSize().x/2, sf::Mouse::getPosition(*this->window).y - (float) this->window->getSize().y/2) * (180/M_PI);
        this->player->setRotation(rot);
        
        this->window->draw(*(this->player));
        
        // end the current frame
        this->window->display();
    }
}
