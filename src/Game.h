#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Menu.h"
#include "Configuration.h"
#include "ActionTarget.h"
#include <SFML/Window.hpp>

class Game : public ActionTarget<int>
{
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();
        void run(int minimum_frame_per_seconds);

    private:

        void processEvents();
        void update(sf::Time deltaTime);
        void initGui();
        void initGame();
        void render();
        sf::RenderWindow _window;
        Menu _mainMenu;
        Player _player;

        enum Status {
            StatusMainMenu,
            StatusGame
            //StatusPaused,
            //StatusExit
        } _status;
};

#endif // GAME_H
