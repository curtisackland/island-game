#include "Player.hpp"

Player::Player(int layer) : GameEntity(layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/player.png"));
    this->setMapLayer(0);
}

Player::~Player(){}

int Player::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/player.png")->getSize().x;
}

void Player::update() {
    float speed = 300;
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) 
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        speed = speed*this->diagonalScalar;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        int x = (int) floor((this->getPosition().x-speed*GameState::getDeltaTime() - this->getGlobalBounds().width/2)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y1 = (int) floor((this->getPosition().y + this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y2 = (int) floor((this->getPosition().y - this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());

        if((this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x, y1)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x, y2)->isWalkable())){

        }else {
            this->move(-speed*GameState::getDeltaTime(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        int x = (int) floor((this->getPosition().x + speed*GameState::getDeltaTime() + this->getGlobalBounds().width/2)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y1 = (int) floor((this->getPosition().y + this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y2 = (int) floor((this->getPosition().y - this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());

        if((this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x, y1)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x, y2)->isWalkable())){

        } else {
            this->move(speed*GameState::getDeltaTime(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        int x1 = (int) floor((this->getPosition().x + this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int x2 = (int) floor((this->getPosition().x - this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y = (int) floor((this->getPosition().y - speed*GameState::getDeltaTime() - this->getGlobalBounds().height/2)/MainWindow::getInstance().getSize().x * GameState::getTileSize());

        if((this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x1, y)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x2, y)->isWalkable())){
        } else {
            this->move(0, -speed*GameState::getDeltaTime());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        int x1 = (int) floor((this->getPosition().x + this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int x2 = (int) floor((this->getPosition().x - this->getGlobalBounds().width/4)/MainWindow::getInstance().getSize().x * GameState::getTileSize());
        int y = (int) floor((this->getPosition().y + speed*GameState::getDeltaTime() + this->getGlobalBounds().height/2)/MainWindow::getInstance().getSize().x * GameState::getTileSize());

        if((this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x1, y)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getMaps()->at(this->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
            && !GameState::getMaps()->at(this->getMapLayer())->getTile(x2, y)->isWalkable())){
        } else {
            this->move(0, speed*GameState::getDeltaTime());
        }
    }
    this->setRotation(180 - atan2(sf::Mouse::getPosition(MainWindow::getInstance()).x - (float) MainWindow::getInstance().getSize().x/2, sf::Mouse::getPosition(MainWindow::getInstance()).y - (float) MainWindow::getInstance().getSize().y/2) * (180/M_PI));
}