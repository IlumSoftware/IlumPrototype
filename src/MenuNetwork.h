#ifndef MENUNETWORK_H
#define MENUNETWORK_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "ActionTarget.h"
#include <string>
#include <iostream>



class MenuNetwork : public sf::Drawable , public ActionTarget<int>
//class MenuNetwork : public sf::Drawable
{
    public:
        MenuNetwork(const MenuNetwork&) = delete;
        MenuNetwork& operator=(const MenuNetwork&) = delete;
        MenuNetwork();


        template<typename ... Args>
        void setPosition(Args&& ... args);
        void update(sf::Time deltaTime);
        void processEvents();
        void processEvent(sf::Event event);

        static void setDefaultsInputs();
        bool isSelected(sf::Vector2f vPos);
        void setFocus(bool focus);
        void setWindowSize(sf::Vector2u _size);


    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        bool _isActive;

        sf::Sprite _background; // Image of background

        sf::Text _lbHostname;     // Label HOSTNAME
        sf::Text _tfHostname;     // HOSTNAME of SERVER
        sf::RectangleShape _rectShapeHostname; // Rectangle visible behind the text to delimited input field
        sf::Text _lbPort;         // Label PORT
        sf::Text _tfPort;         // PORT OF SERVER

        sf::Text _lbConsole;       // Label CONSOLE
        sf::Text _tfConsole;       // Field area contains status and information of connection
        //sf::Sprite _button;
        sf::FloatRect _rect;
        //bool _isClick = false;
        std::string m_text;
        bool m_hasfocus;
        unsigned int m_size;

        // Window information
        sf::Vector2u w_size;   // get from target

        //Add all menu's elements
};
#include "MenuNetwork.tpl"
#endif // MENUNETWORK_H
