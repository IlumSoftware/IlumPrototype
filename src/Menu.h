#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "ActionTarget.h"


class Menu : public sf::Drawable , public ActionTarget<int>
{
    public:
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        Menu();

        template<typename ... Args>
        void setPosition(Args&& ... args);
        void update(sf::Time deltaTime);
        void processEvents();
        void processEvent(sf::Event event);

        static void setDefaultsInputs();
        bool isSelected(sf::Vector2f vPos);


    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        bool _isActive;

        sf::Sprite _button;
        sf::FloatRect _rect;
        bool _isClick = false;

        //Add all menu's elements
};
#include "Menu.tpl"
#endif // MENU_H
