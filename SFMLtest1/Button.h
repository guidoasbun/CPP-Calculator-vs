#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Button
{
private:
	sf::RectangleShape button;
	char value;

public:
	//Constructors
	Button();
	Button(float xCoordinates, float yCoordinates, char val);

	//Getters
	sf::RectangleShape getButtonShape();
	char getValue();

	//Setters
	void setButtonPosition(float xCoordinates, float yCoordinates);
	void setFillColor();
	void setButtonValue(char val);

};

