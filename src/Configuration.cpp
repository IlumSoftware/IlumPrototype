#include "Configuration.h"
#include <SFML/Graphics.hpp>


ResourceManager<sf::Font,int> Configuration::fonts;
ResourceManager<sf::Texture,int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;
ActionMap<int> Configuration::guiInputs;
ActionMap<int> Configuration::menuInputs;


void Configuration::initialize()
{
    initTextures();
    initFonts();
    initPlayerInputs();
    initGuiInputs();
    initMenuInputs();
}

void Configuration::initTextures()
{
    textures.load(Textures::Player,"media/Player/Ship.png");

    textures.load(Textures::ButtonSinglePlayer,"media/Menu/SinglePlayer.png");
    textures.load(Textures::ButtonSinglePlayer2,"media/Menu/SinglePlayer2.png");

    textures.load(Textures::ButtonMultiPlayer,"media/Menu/MultiPlayer.png");
    textures.load(Textures::ButtonMultiPlayer2,"media/Menu/MultiPlayer2.png");

    textures.load(Textures::ButtonQuit,"media/Menu/Quit.png");
    textures.load(Textures::ButtonQuit2,"media/Menu/Quit2.png");

    textures.load(Textures::BackgroundMainMenu,"media/Menu/BackgroundMainMenu.png");
    textures.load(Textures::BackgroundMenuNetwork,"media/Menu/BackgroundMenuNetwork.png");
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

void Configuration::initMenuInputs()
{
    menuInputs.map(MenuInputs::MouseLeft,Action(sf::Mouse::Left));

    menuInputs.map(MenuInputs::EnterN,Action(sf::Keyboard::Enter));
}
