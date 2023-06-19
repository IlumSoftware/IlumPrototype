#include "MenuNetwork.h"
#include "Configuration.h"
#include <math.h>
#include <iostream>


MenuNetwork::MenuNetwork(Status& status) : ActionTarget(Configuration::menuInputs),m_hasfocus(true),m_size(50)
//MenuNetwork::MenuNetwork()
{

    //Add all element (box, textbox, etc...)
    //FIELDS
    _lbHostname.setFont(Configuration::fonts.get(Configuration::Fonts::Menu));
    _lbHostname.setCharacterSize(22);                                            // Label HOSTNAME
    _lbHostname.setString("Server Name or IP Address");

    _tfHostname.setFont(Configuration::fonts.get(Configuration::Fonts::Menu));     // HOSTNAME of SERVER
    _tfHostname.setCharacterSize(22);
    _tfHostname.setString("|_________________________________________________|"); // 50 chars with | to set correct size of rectangleShape
    _rectShapeHostname.setSize(sf::Vector2f(_tfHostname.getLocalBounds().width+10,_tfHostname.getLocalBounds().height+10));

    _rectShapeHostname.setFillColor(sf::Color(128,128,128,128));
    _rectShapeHostname.setOutlineColor(sf::Color(255,255,255));
    _rectShapeHostname.setOutlineThickness(2.0f);

    _lbPort.setFont(Configuration::fonts.get(Configuration::Fonts::Menu));         // Label PORT
    _lbPort.setCharacterSize(22);
    _lbPort.setString("Server Port (default:50001) ");
    _tfPort.setFont(Configuration::fonts.get(Configuration::Fonts::Menu));         // PORT OF SERVER
    _tfPort.setCharacterSize(22);

    //BACKGROUND
    _background.setTexture(Configuration::textures.get(Configuration::Textures::BackgroundMenuNetwork));
    //bind all mouse events
   // bind(Configuration::MenuInputs::A,[this](const sf::Event&){m_text += "a";});
}

void MenuNetwork::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();



    _tfHostname.setString(m_text);

    /// gerer l'état des boutons (si cliqué ou non)

}

void MenuNetwork::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(_background,states);
    target.draw(_lbHostname,states);
    target.draw(_rectShapeHostname,states);
    target.draw(_tfHostname,states);
    //target.draw de tous les elements du menu
}

void MenuNetwork::processEvents()
{
   // ActionTarget::processEvents();
}
void MenuNetwork::processEvent(sf::Event event)
{
    std::cout << "TextField handleInput : " << event.type << std::endl;
    std::cout << "m_text avant : " << m_text << std::endl;
    if (!m_hasfocus || event.type != sf::Event::TextEntered){
        std::cout << "Return ...." << std::endl;
        return;
    }

    if (event.text.unicode == 8){   // Delete key
        m_text = m_text.substr(0, m_text.size() - 1);
    }
    else if (m_text.size() < m_size){

        m_text += event.text.unicode;
        std::cout << "m_text : " << m_text << std::endl;
    }
  //  _tfHostname.setFocus(true);
    //_tfHostname.handleInput(event);
   // ActionTarget::processEvent(event);
    //_tfHostname.setString(m_text);
}
bool MenuNetwork::isSelected(sf::Vector2f vPos)
{

    //return _tfHostname.contains(vPos);

    _rect = _tfHostname.getGlobalBounds();
    if (_rect.contains(vPos))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void MenuNetwork::setFocus(bool focus)
{
    m_hasfocus = focus;
}

void MenuNetwork::setWindowSize(sf::Vector2u _size){
    w_size = _size;
    std::cout << "Window size X: " << w_size.x << " Y: " << w_size.y << std::endl;
      //Position des objets
    //sf::FloatRect f_rect = _lbHostname.getLocalBounds();
    //_background.setScale(w_size);
    _lbHostname.setPosition(10,w_size.y/90.0f);
    _tfHostname.setPosition(_lbHostname.getPosition().x+_lbHostname.getGlobalBounds().width+10,w_size.y/90.0f);
    _rectShapeHostname.setPosition(_tfHostname.getPosition().x,_tfHostname.getPosition().y);
    std::cout << "hostname size X: " << _lbHostname.getGlobalBounds().width << " Y: " << _lbHostname.getGlobalBounds().height << std::endl;
    //_rectShapeHostname.setSize(sf::Vector2f(_tfHostname.getLocalBounds().width,_tfHostname.getLocalBounds().height));
    //_rectShapeHostname.setSize(sf::Vector2f(_tfHostname.getGlobalBounds().width,_tfHostname.getGlobalBounds().height));
    // _rectShapeHostname.setSize(sf::Vector2f(w_size.x/2,_lbHostname.getGlobalBounds().height));
}
