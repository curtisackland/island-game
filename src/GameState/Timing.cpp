#include "Timing.hpp"

float Timing::getDeltaTime() const {
    return this->deltaTime;
}

void Timing::resetTimer(){
    this->deltaTime = this->clock.restart().asSeconds();
}
