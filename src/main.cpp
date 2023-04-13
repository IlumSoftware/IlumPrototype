#include "Game.h"
#include "Player.h"

int main(int argc,char* argv[])
{
    int minimum_frame_per_seconds = 30;
    Player::setDefaultsInputs();
    Game game;
    game.run(minimum_frame_per_seconds);
    return 0;
}
