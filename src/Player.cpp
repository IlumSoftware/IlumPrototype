#include "Player.h"
#include "Configuration.h"
#include <math.h>
//ActionMap<int> Player::_playerInputs;

Player::Player() : ActionTarget(Configuration::playerInputs)
                    //,_shape(sf::Vector2f(32,32))
                    ,_isMoving(false)
                    ,_rotation(0)
{
    //_shape.setFillColor(sf::Color::Blue);
    //_shape.setOrigin(16,16);
    _ship.setTexture(Configuration::textures.get(Configuration::Textures::Player));
    _ship.setOrigin(49.5,37.5);

    bind(Configuration::PlayerInputs::Up,[this](const sf::Event&){_isMoving = true;});
    bind(Configuration::PlayerInputs::Left,[this](const sf::Event&){_rotation-= 1;});
    bind(Configuration::PlayerInputs::Right,[this](const sf::Event&){_rotation+= 1;});
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    if(_rotation != 0)
    {
        //float angle = (rotation>0?1:-1)*180*seconds;
        float angle = _rotation*180*seconds;
        //_shape.rotate(angle);
        _ship.rotate(angle);
    }
    if(_isMoving)
    {
        //float angle = _shape.getRotation() / 180 * M_PI - M_PI / 2;
        float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;

        _velocity += sf::Vector2f(cos(angle),sin(angle)) * 60.f * seconds;
    }
    _ship.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(_shape,states);
    target.draw(_ship,states);
}

void Player::processEvents()
{
    //_isMoving = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    _isMoving = false;
    _rotation = 0;
    //_rotation-= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    //_rotation+= sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    ActionTarget::processEvents();
}

/*void Player::setDefaultsInputs()
{
    _playerInputs.map(PlayerInputs::Up,Action(sf::Keyboard::Up));
    _playerInputs.map(PlayerInputs::Right,Action(sf::Keyboard::Right));
    _playerInputs.map(PlayerInputs::Left,Action(sf::Keyboard::Left));
}*/
