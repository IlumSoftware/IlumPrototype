#include "Game.h"

#include "Configuration.h"

int main(int argc,char* argv[])
{
    int minimum_frame_per_seconds = 30;
    Configuration::initialize();

    Game game;
    game.run(minimum_frame_per_seconds);
    return 0;
}
