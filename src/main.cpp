#include "Game.hpp"

int main()
{
    Game *game = new Game();
    game->gameLoop();
    delete game;
    return 0;
}
