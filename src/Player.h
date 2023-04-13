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


        enum PlayerInputs {Up,Left,Right};
        static void setDefaultsInputs();


    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::RectangleShape _shape;
        sf::Vector2f _velocity;

        bool _isMoving;
        int _rotation;

        static ActionMap<int> _playerInputs;
};
#include "Player.tpl"
#endif // PLAYER_H
