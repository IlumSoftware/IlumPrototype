#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "Status.h"

Game::Game() : ActionTarget(Configuration::playerInputs),_window(sf::VideoMode(resX, resY),"War Ships"),status(), _player(), _mainMenu(status), _networkMenu(status)
{
    view.setSize( resX, resY );
    view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
    view = getLetterboxView( view, resX, resY );

    _status = Status::CurrentStatus::MainMenu;
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
                    std::cout << "main menu bind" << std::endl;
                    //status.setCurrentButton(this->_mainMenu.whichButton((sf::Vector2f)sf::Mouse::getPosition(this->_window)));
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
                    sf::Vector2f worldPos = _window.mapPixelToCoords(pixelPos);
                    status.setCurrentButton(_mainMenu.whichButton(worldPos));
                    //status.setCurrentButton(_mainMenu.whichButton((sf::Vector2f)sf::Mouse::getPosition(_window)));
                    //status.setCurrentButton(this->_mainMenu.whichButton((sf::Vector2f)sf::Mouse::getPosition()));
                    switch(status.getCurrentButton())
                    {
                        case Status::CurrentButton::BClickSinglePlayer:
                        {
                                status.setCurrentStatus(Status::CurrentStatus::SingleGame);
                                _status = status.getCurrentStatus();
                        }break;
                        case Status::CurrentButton::BClickMultiPlayer:
                        {
                                //status.setCurrentStatus(Status::CurrentStatus::MultiGame);
                                status.setCurrentStatus(Status::CurrentStatus::NetworkMenu);
                                _status = status.getCurrentStatus();
                                initNetworkMenu();
                        }break;
                        case Status::CurrentButton::BClickQuit:
                        {
                                status.setCurrentStatus(Status::CurrentStatus::Quit);
                                _status = status.getCurrentStatus();
                        }break;
                        case Status::CurrentButton::Nothing:
                        {
                                status.setCurrentStatus(Status::CurrentStatus::MainMenu);
                                _status = status.getCurrentStatus();
                        }break;
                    }
                    //_mainMenu.updateButtons();

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

                             // _status = Status::StatusMainMenu;
                             status.setCurrentStatus(Status::CurrentStatus::MainMenu);

                         }
                         else
                         {
                            // _status = Status::StatusNetworkMenu;
                             status.setCurrentStatus(Status::CurrentStatus::NetworkMenu);

                         }
                         _status = status.getCurrentStatus();
                     }
    });
}

void Game::processEvents() {
    sf::Event event;
    while(_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed or status.getCurrentStatus() == Status::CurrentStatus::Quit)
        {
            _window.close();
        }
        else if (event.type == sf::Event::MouseMoved){
            sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
            sf::Vector2f worldPos = _window.mapPixelToCoords(pixelPos);
            _mainMenu.updateButtons(worldPos);
        }
        else if (event.type == sf::Event::Resized){
                view = getLetterboxView( view, event.size.width, event.size.height );
                _mainMenu.setWindowSize((sf::Vector2u)view.getSize());
                _networkMenu.setWindowSize((sf::Vector2u)view.getSize());

        }
        else if (event.type == sf::Event::KeyPressed or (event.type == sf::Event::MouseButtonPressed and _status == Status::CurrentStatus::MainMenu) or (event.type == sf::Event::TextEntered and _status == Status::CurrentStatus::NetworkMenu)){

            switch(_status)
            {
                case Status::CurrentStatus::MainMenu:
                {
                    _mainMenu.processEvent(event);
                }break;
                case Status::CurrentStatus::NetworkMenu:
                {
                    _networkMenu.processEvent(event);
                }break;
                case Status::CurrentStatus::SingleGame :
                {
                    ActionTarget::processEvent(event);
                }break;
                default : break;
            }
            std::cout << "Status in Game: " << status.getCurrentStatus() << std::endl;
        }

    }
    switch(_status)
    {
        case Status::CurrentStatus::MainMenu:
        {
            _mainMenu.processEvents();
        }break;
        case Status::CurrentStatus::NetworkMenu:
        {
            _networkMenu.processEvents();
        }break;
        case Status::CurrentStatus::SingleGame :
        {
            //ActionTarget::processEvents();
            _player.processEvents();
        }break;
        default : break;
    }
}

void Game::update(sf::Time deltaTime){

    switch(_status)
    {
        case Status::CurrentStatus::MainMenu:
        {
            _mainMenu.update(deltaTime);

        }break;
        case Status::CurrentStatus::NetworkMenu:
        {
            _networkMenu.update(deltaTime);

        }break;
        case Status::CurrentStatus::SingleGame :
        {
            _player.update(deltaTime);
        }break;
        default : break;
    }
}

void Game::render() {
    _window.clear();
    _window.setView(view);
    switch(_status)
    {
        case Status::CurrentStatus::MainMenu:
        {
            _window.draw(_mainMenu);
        }break;
        case Status::CurrentStatus::SingleGame :
        {
            _window.draw(_player);

        }break;
        case Status::CurrentStatus::NetworkMenu:
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

