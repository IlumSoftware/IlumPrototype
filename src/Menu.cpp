#include "Menu.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>


Menu::Menu() : ActionTarget(Configuration::guiInputs)
                    ,_isActive(true)
{

    //Add all element (box, textbox, etc...)
      _button.setTexture(Configuration::textures.get(Configuration::Textures::StartButton));

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
    target.draw(_button,states);
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
    _rect = _button.getGlobalBounds();
    if (_rect.contains(vPos))
    {
        return true;
    }
    else
    {
        return false;
    }
}
