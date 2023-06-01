#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <SFML/Graphics.hpp> //Texture

#include "ResourceManager.h" //ResourceManager
#include "ActionMap.h" //ActionMap

class Configuration
{
    public:
        Configuration() = delete;
        Configuration(const Configuration&) = delete;
        Configuration& operator=(const Configuration&) = delete;

        enum Textures : int {Player,StartButton};
        static ResourceManager<sf::Texture,int> textures;

        enum Fonts : int {Menu};
        static ResourceManager<sf::Font,int> fonts;

        enum PlayerInputs : int {Up,Left,Right};
        static ActionMap<int> playerInputs;

        enum GuiInputs : int {
                Enter,
                Escape,
                MouseBLeft
            };
        static ActionMap<int> guiInputs;

        static void initialize();

    private:
        static void initFonts();
        static void initTextures();

        static void initPlayerInputs();
        static void initGuiInputs();
};
#endif

