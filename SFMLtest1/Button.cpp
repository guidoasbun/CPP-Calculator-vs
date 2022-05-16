#include "Button.h"


Button::Button()
{
}

//Getters
sf::RectangleShape Button::getButtonShape()
{
	return button;
}

char Button::getValue()
{
	return value;
}

void Button::setButtonSize(float x, float y)
{
	button.setSize(sf::Vector2f(x, y));
}

//Setters
void Button::setButtonPosition(float xCoordinates, float yCoordinates)
{
	button.setPosition(xCoordinates, yCoordinates);
}

void Button::setFillColor(double red, double green, double blue)
{
	button.setFillColor(sf::Color(red, green, blue));
}

void Button::setButtonValue(char val)
{
	value = val;
}