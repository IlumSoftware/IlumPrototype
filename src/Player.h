#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "ActionTarget.h"
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class Player : public sf::Drawable , public ActionTarget<int>
{
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player();
        template<typename ... Args>
        void setPosition(Args&& ... args);
        void update(sf::Time deltaTime);
        void processEvents();
        static void setDefaultsInputs();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::Sprite          _ship;
        sf::Vector2f _velocity;
        bool _isMoving;
        int _rotation;
};
#include "Player.tpl"
#endif // PLAYER_H
