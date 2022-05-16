//
// Created by Rodrigo Asbun on 5/7/22.
//
/*
 * class that acts as the game engine
 */

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Calculator
{
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Text
    sf::Font font;
    sf::Text uiText;

    //Calculator Objects
    Button button;

    std::vector<Button> opButton;
    std::vector<Button> numButton;
	Button equals;

    sf::RectangleShape display;
    

    //Private Init Functions
    void initVariables();
    void initWindow();
    void initDisplay();
    void initFonts();
    void initDisplayText();
    void initOperators();
    void initNumbers();
    void initEquals();

public:
    //Constructors / Destructors
    Calculator();
    virtual ~Calculator();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();

    //Update Functions
    void updateMousePosition();
    void updateDisplayText();
    void update();

    //Render functions
    void renderDisplayText(sf::RenderTarget& target);
    void renderDisplay(sf::RenderTarget& target);
    void renderOperators(sf::RenderTarget& target);
    void renderNumbers(sf::RenderTarget& target);
    void renderEquals(sf::RenderTarget& target);
    void render();
};
