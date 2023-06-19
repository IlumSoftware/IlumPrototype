#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Menu.h"
#include "MenuNetwork.h"
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
        void initNetworkMenu();
        void initGame();
        void render();
        sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight);
        sf::View disableLetterboxView(sf::View view);
        int resX = 1024; // Window Width
        int resY = 768; // Windiw Height
        sf::RenderWindow _window;
        sf::View view;
        Status status;
        Menu _mainMenu;
        MenuNetwork _networkMenu;
        Player _player;

/*
        enum Status :int{
            StatusMainMenu,
            StatusGame,
            StatusNetworkMenu
            //StatusPaused,
            //StatusExit
        } _status;
        */
        int _status;
};

#endif // GAME_H
