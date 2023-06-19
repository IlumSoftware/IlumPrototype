#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "ActionTarget.h"
#include "Status.h"
#include <map>
using namespace std;


class Menu : public sf::Drawable , public ActionTarget<int>
{
    public:
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        Menu(Status& status);

        template<typename ... Args>
        void setPosition(Args&& ... args);
        void update(sf::Time deltaTime);
        void processEvents();
        void processEvent(sf::Event event);

        static void setDefaultsInputs();

        int whichButton(sf::Vector2f vPos);

        void updateButtons(sf::Vector2f worldPos);

        void setWindowSize(sf::Vector2u _size);




    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        bool _isActive;
        Status status;
        sf::Sprite _background; // Image of background
        sf::Sprite _btSingle;
        sf::Sprite _btMulti;
        sf::Sprite _btQuit;
        sf::FloatRect _rect;

        map<int,sf::FloatRect> listPosButton;

        bool _isClick = false; // Not used !

        // Window information
        sf::Vector2u w_size;   // get from target



        //Add all menu's elements
};
#include "Menu.tpl"
#endif // MENU_H
