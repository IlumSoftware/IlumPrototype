#include "Game.h"
#include "Player.h"
#include "Menu.h"

Game::Game() : ActionTarget(Configuration::playerInputs), _window(sf::VideoMode(800, 600),"War Ships"), _player(), _mainMenu()
{
   _status = Status::StatusMainMenu;
    _player.setPosition(100,100);
    _mainMenu.setPosition(100,100);
    initGui();
}

void Game::run(int minimum_frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f/minimum_frame_per_seconds);
    while (_window.isOpen()) {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
}

void Game::initGui()
{
   _mainMenu.bind(Configuration::GuiInputs::MouseBLeft,[this](const sf::Event& event){
                     if (this->_mainMenu.isSelected((sf::Vector2f)sf::Mouse::getPosition(this->_window)))
                     {
                         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                         {
                             _status = Status::StatusGame;
                                initGame();
                         }
                         else
                         {
                              _status = Status::StatusMainMenu;
                         }
                     }
                   });
}


void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }
       else if (event.type == sf::Event::KeyPressed or (event.type == sf::Event::MouseButtonPressed and _status == Status::StatusMainMenu)){
            switch(_status)
            {
                case StatusMainMenu:
                {
                    _mainMenu.processEvent(event);
                }break;
                case StatusGame :
                {
                    ActionTarget::processEvent(event);
                }break;
                default : break;
            }
        }

    }
    switch(_status)
    {
        case StatusMainMenu:
        {
            _mainMenu.processEvents();
        }break;
        case StatusGame :
        {
            ActionTarget::processEvents();
        }break;
        default : break;
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime){
    _mainMenu.update(deltaTime);
    _player.update(deltaTime);
}

void Game::render() {
    _window.clear();
    switch(_status)
    {
        case StatusMainMenu:
        {
            _window.draw(_mainMenu);
        }break;
        case StatusGame :
        {
            _window.draw(_player);

        }break;
        default : break;
    }

    _window.display();
}

void Game::initGame()
{
}

