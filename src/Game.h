#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
class Game
{
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();
        void run(int minimum_frame_per_seconds);

    private:

        void processEvents();
        void update(sf::Time deltaTime);

        void render();
        sf::RenderWindow _window;
        //sf::CircleShape _player;
        Player _player;
};

#endif // GAME_H
