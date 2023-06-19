#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <SFML/Graphics.hpp> //Texture

#include "ResourceManager.h" //ResourceManager
#include "ActionMap.h" //ActionMap

class Configuration
{
    public:
        Configuration() = delete;
        Configuration(const Configuration&) = delete;
        Configuration& operator=(const Configuration&) = delete;

        enum Textures : int {
            Player,
            BackgroundMainMenu,
            BackgroundMenuNetwork,
            ButtonSinglePlayer,
            ButtonMultiPlayer,
            ButtonQuit,
            ButtonSinglePlayer2,
            ButtonMultiPlayer2,
            ButtonQuit2
            };
        static ResourceManager<sf::Texture,int> textures;

        enum Fonts : int {Menu,MenuNetwork};
        static ResourceManager<sf::Font,int> fonts;

        enum PlayerInputs : int {Up,Left,Right};
        static ActionMap<int> playerInputs;

        enum GuiInputs : int {
                Enter,
                Escape,
                MouseBLeft
            };
        static ActionMap<int> guiInputs;

        enum MenuInputs : int {
                MouseLeft,
                EnterN
            };
        static ActionMap<int> menuInputs;

        static void initialize();

    private:
        static void initFonts();
        static void initTextures();

        static void initPlayerInputs();
        static void initGuiInputs();
        static void initMenuInputs();
};
#endif

