#include "Game.h"
#include "Player.h"

Game::Game() : _window(sf::VideoMode(800, 600),"02_Game_Archi"), _player()
{
    //_player.setFillColor(sf::Color::Blue);
    //_player.setPosition(10, 20);
    //_player.setDefaultsInputs();
    _player.setPosition(100,100);
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
void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }

    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime){
    _player.update(deltaTime);
}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.display();
}

