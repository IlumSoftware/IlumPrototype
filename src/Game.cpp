#include "Game.h"
#include "Player.h"
#include "Menu.h"

//Game::Game() : ActionTarget(Configuration::playerInputs), _window(sf::VideoMode(800, 600),"War Ships"), _player(), _mainMenu(), _networkMenu()
Game::Game() : ActionTarget(Configuration::playerInputs),_window(sf::VideoMode(resX, resY),"War Ships"), _player(), _mainMenu(), _networkMenu()
{
    //resX = 800;
    //resY = 600;

    view.setSize( resX, resY );
    view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
    view = getLetterboxView( view, resX, resY );

    _status = Status::StatusMainMenu;
    _player.setPosition(100,100);
    _mainMenu.setPosition(0,0);
    _networkMenu.setPosition(0,0);
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
   _mainMenu.setWindowSize(this->_window.getSize());
   _mainMenu.bind(Configuration::GuiInputs::MouseBLeft,[this](const sf::Event& event){
                     if (this->_mainMenu.isSelected((sf::Vector2f)sf::Mouse::getPosition(this->_window)))
                     {
                         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                         {
                             // Comment for testing MenuNetwork
                             //_status = Status::StatusGame;
                             //   initGame();

                             _status = Status::StatusNetworkMenu;
                             initNetworkMenu();
                         }
                         else
                         {
                              _status = Status::StatusMainMenu;
                         }
                     }
                   });
}

void Game::initNetworkMenu()
{
    _networkMenu.setWindowSize(this->_window.getSize());
    _networkMenu.bind(Configuration::MenuInputs::MouseLeft,[this](const sf::Event& event){
                     if (this->_networkMenu.isSelected((sf::Vector2f)sf::Mouse::getPosition(this->_window)))
                     {
                         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                         {
                             // Comment for testing MenuNetwork
                             //_status = Status::StatusGame;
                             //   initGame();

                              _status = Status::StatusMainMenu;

                         }
                         else
                         {
                             _status = Status::StatusNetworkMenu;

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
        else if (event.type == sf::Event::Resized){
                view = getLetterboxView( view, event.size.width, event.size.height );
        }
        else if (event.type == sf::Event::KeyPressed or (event.type == sf::Event::MouseButtonPressed and _status == Status::StatusMainMenu) or (event.type == sf::Event::TextEntered and _status == Status::StatusNetworkMenu)){
            switch(_status)
            {
                case StatusMainMenu:
                {
                    _mainMenu.processEvent(event);
                }break;
                case StatusNetworkMenu:
                {
                    _networkMenu.processEvent(event);
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
        case StatusNetworkMenu:
        {
            _networkMenu.processEvents();
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
    _networkMenu.update(deltaTime);
    _player.update(deltaTime);
}

void Game::render() {
    _window.clear();
    _window.setView(view);
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
        case StatusNetworkMenu:
        {
            _window.draw(_networkMenu);
        }break;
        default : break;
    }

    _window.display();
}

void Game::initGame()
{

}

sf::View Game::getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}

sf::View Game::disableLetterboxView(sf::View view) {

    view.setViewport( sf::FloatRect(0, 0, 1, 1) );
    return view;
}

