#include "Game.hpp"

Game::Game(){
    this->window = new sf::RenderWindow(sf::VideoMode(1600, 900), "My Game");
    this->player = new sf::RectangleShape(sf::Vector2f((float) window->getSize().x/15, (float) window->getSize().x/15));

    sf::Texture spriteTexture;
    if (!spriteTexture.loadFromFile("test1.png"))
    {
        // error...
        printf("weird\n");
    }
    sf::Texture *texture = &spriteTexture;
    this->player->setTexture(texture);
    this->player->setFillColor(sf::Color(255,255,255));
}



void Game::gameLoop(){
    sf::Clock clock;
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
                //case sf::Event::KeyPressed:
                default:
                    break;
            }
        }


        float deltaTime = clock.restart().asSeconds();
        // clear the window with black color
        window->clear(sf::Color::Black);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            // left key is pressed: move our character
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
        this->window->draw(*(this->player));
        
        
        // end the current frame
        this->window->display();
    }
}
