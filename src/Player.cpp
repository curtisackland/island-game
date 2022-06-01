#include "Player.hpp"

Player::Player(){
    this->setTexture(*TextureFactory::getTexture("resources/images/player.png"));
}

Player::~Player(){}

int Player::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/player.png")->getSize().x;
}
