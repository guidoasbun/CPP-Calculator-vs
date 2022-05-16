#pragma once

#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape button;
	char value;

public:
	//Constructors
	Button();

	//Getters
	sf::RectangleShape getButtonShape();
	char getValue();

	//Setters
	void setButtonSize(float x, float y);
	void setButtonPosition(float xCoordinates, float yCoordinates);
	void setFillColor(double red, double green, double blue);
	void setButtonValue(char val);
};

