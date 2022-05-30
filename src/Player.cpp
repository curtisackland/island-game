#include "Player.hpp"

Player::Player(){
    this->texture = new sf::Texture();
    if(!this->texture->loadFromFile("player.png")){
        printf("Error loading tile sprite.\n");
    }
    this->setTexture(*this->texture);
}

Player::~Player(){}

int Player::getTextureWidth(){
    return this->texture->getSize().x;
}
