#include "Menu.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>


Menu::Menu() : ActionTarget(Configuration::guiInputs)
                    ,_isActive(true)
{

    //Add all element (box, textbox, etc...)
      //_button.setTexture(Configuration::textures.get(Configuration::Textures::StartButton));
    _btSingle.setTexture(Configuration::textures.get(Configuration::Textures::ButtonSinglePlayer));
    _btMulti.setTexture(Configuration::textures.get(Configuration::Textures::ButtonMultiPlayer));
    _btQuit.setTexture(Configuration::textures.get(Configuration::Textures::ButtonQuit));
      //BACKGROUND
    _background.setTexture(Configuration::textures.get(Configuration::Textures::BackgroundMainMenu));

    //bind all mouse events
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
bool Menu::isSelected(sf::Vector2f vPos)
{
    //_rect = _button.getGlobalBounds();
    _rect = _btMulti.getGlobalBounds();
    if (_rect.contains(vPos))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Menu::setWindowSize(sf::Vector2u _size){
    w_size = _size;
    std::cout << "Window size X: " << w_size.x << " Y: " << w_size.y << std::endl;
      //Position des objets
   // _btSingle.setPosition((w_size.y/2) - (_btSingle.getLocalBounds().width/2),w_size.y/4);
    _btSingle.setPosition(w_size.y/2,w_size.y/4.5);
    _btMulti.setPosition(w_size.y/2,w_size.y/3);
    _btQuit.setPosition(w_size.y/2,w_size.y/1.5);

}
