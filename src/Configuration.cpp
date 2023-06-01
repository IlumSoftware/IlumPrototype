#include "Configuration.h"
#include <SFML/Graphics.hpp>


ResourceManager<sf::Font,int> Configuration::fonts;
ResourceManager<sf::Texture,int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;
ActionMap<int> Configuration::guiInputs;

void Configuration::initialize()
{
    initTextures();
    initFonts();
    initPlayerInputs();
    initGuiInputs();
}

void Configuration::initTextures()
{
    textures.load(Textures::Player,"media/Player/Ship.png");
    textures.load(Textures::StartButton,"media/Menu/StartButton.png");
}

void Configuration::initFonts()
{
    fonts.load(Fonts::Menu,"media/font/arial.ttf");
}

void Configuration::initPlayerInputs()
{
    playerInputs.map(PlayerInputs::Up,Action(sf::Keyboard::Up));
    playerInputs.map(PlayerInputs::Right,Action(sf::Keyboard::Right));
    playerInputs.map(PlayerInputs::Left,Action(sf::Keyboard::Left));
}

void Configuration::initGuiInputs()
{
    guiInputs.map(GuiInputs::Escape,Action(sf::Keyboard::Escape));
    guiInputs.map(GuiInputs::Enter,Action(sf::Keyboard::Enter));
    guiInputs.map(GuiInputs::MouseBLeft,Action(sf::Mouse::Left));

}
