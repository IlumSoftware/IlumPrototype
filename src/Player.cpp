#include "Player.h"
#include "Configuration.h"
#include "ParticleSystem.h"
#include <math.h>
//ActionMap<int> Player::_playerInputs;

Player::Player() : ActionTarget(Configuration::playerInputs)
                    ,_isMoving(false)
                    ,_rotation(0)
                    ,particles(1000)  // on crée un système de 1000 particules
{
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
        _ship.rotate(angle);
    }
    if(_isMoving)
    {
        float angle = _ship.getRotation() / 180 * M_PI - M_PI / 2;

        _velocity += sf::Vector2f(cos(angle),sin(angle)) * 60.f * seconds;
    }
    _ship.move(seconds * _velocity);
    particles.setEmitter(_ship.getPosition());
    particles.update(deltaTime);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(particles,states);
    target.draw(_ship,states);
    
}

void Player::processEvents()
{
    _isMoving = false;
    _rotation = 0;
    ActionTarget::processEvents();
}
