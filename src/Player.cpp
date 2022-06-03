#include "Player.hpp"

Player::Player(){
    this->setTexture(*TextureFactory::getTexture("resources/images/player.png"));
    this->setMapLayer(0);
}

Player::~Player(){}

int Player::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/player.png")->getSize().x;
}

void Player::update() {

}