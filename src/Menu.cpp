#include "Menu.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>
#include <map>
#include "Status.h"
using namespace  std;

Menu::Menu(Status& status) : ActionTarget(Configuration::guiInputs),status(status)
{

    //Add all element (box, textbox, etc...)
    _btSingle.setTexture(Configuration::textures.get(Configuration::Textures::ButtonSinglePlayer));
    _btMulti.setTexture(Configuration::textures.get(Configuration::Textures::ButtonMultiPlayer));
    _btQuit.setTexture(Configuration::textures.get(Configuration::Textures::ButtonQuit));
      //BACKGROUND
    _background.setTexture(Configuration::textures.get(Configuration::Textures::BackgroundMainMenu));

    std::cout << "Status in main menu: " << status.getCurrentStatus() << std::endl;
    bind(Configuration::GuiInputs::Escape,[this](const sf::Event&){_isActive = false;});
    bind(Configuration::GuiInputs::MouseBLeft,[this](const sf::Event&){_isClick = true;});
}

void Menu::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();

    /// gerer l'état des boutons (si cliqué ou non)

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_background,states);
    target.draw(_btSingle,states);
    target.draw(_btMulti,states);
    target.draw(_btQuit,states);
    //target.draw(_button,states);
    //target.draw de tous les elements du menu
}

void Menu::processEvents()
{
    ActionTarget::processEvents();

}
void Menu::processEvent(sf::Event event)
{
    ActionTarget::processEvent(event);

}


int Menu::whichButton(sf::Vector2f vPos)
{
    int _tmpStatus = Status::CurrentButton::Nothing;

    map<int,sf::FloatRect>::iterator it;

    for(it = listPosButton.begin();it != listPosButton.end(); ++it)
    {
        _rect = it->second;
        if(_rect.contains(vPos))
            _tmpStatus = it->first;
        else
            cout << "listPos : " << it-> first <<  endl;
    }
    cout << "whichButton : " << _tmpStatus << endl;
    return _tmpStatus;
}



void Menu::updateButtons(sf::Vector2f worldPos)
{
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
   // sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
   // sf::Vector2f worldPos = _window.mapPixelToCoords(pixelPos);

    int currentB = whichButton(worldPos);

    switch (currentB)
    {
        case Status::CurrentButton::BClickSinglePlayer:
        {
            _btSingle.setTexture(Configuration::textures.get(Configuration::Textures::ButtonSinglePlayer2));
        }break;
        case Status::CurrentButton::BClickMultiPlayer:
        {
            _btMulti.setTexture(Configuration::textures.get(Configuration::Textures::ButtonMultiPlayer2));
        }break;
        case Status::CurrentButton::BClickQuit:
        {
            _btQuit.setTexture(Configuration::textures.get(Configuration::Textures::ButtonQuit2));
        }break;
        default:
        {
            _btSingle.setTexture(Configuration::textures.get(Configuration::Textures::ButtonSinglePlayer));
            _btMulti.setTexture(Configuration::textures.get(Configuration::Textures::ButtonMultiPlayer));
            _btQuit.setTexture(Configuration::textures.get(Configuration::Textures::ButtonQuit));
        }
    }


}
void Menu::setWindowSize(sf::Vector2u _size){
    w_size = _size;
    std::cout << "Window size X: " << w_size.x << " Y: " << w_size.y << std::endl;
      //Position des objets
    _btSingle.setPosition(w_size.y/2,w_size.y/4.5);
    _btMulti.setPosition(w_size.y/2,w_size.y/3);
    _btQuit.setPosition(w_size.y/2,w_size.y/1.5);

    listPosButton.clear();
    listPosButton.insert(pair<int,sf::FloatRect>(Status::CurrentButton::BClickSinglePlayer,_btSingle.getGlobalBounds()));
    listPosButton.insert(pair<int,sf::FloatRect>(Status::CurrentButton::BClickMultiPlayer,_btMulti.getGlobalBounds()));
    listPosButton.insert(pair<int,sf::FloatRect>(Status::CurrentButton::BClickQuit,_btQuit.getGlobalBounds()));
}
