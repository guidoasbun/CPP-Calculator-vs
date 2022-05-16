#include "Button.h"


Button::Button()
{
}

Button::Button(float xCoordinates, float yCoordinates, char val)
{
	button.setPosition(xCoordinates, yCoordinates);
	value = val;
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

//Setters
void Button::setButtonPosition(float xCoordinates, float yCoordinates)
{
	button.setPosition(xCoordinates, yCoordinates);
}

void Button::setFillColor()
{
	button.setFillColor(sf::Color(79, 79, 79));
}

void Button::setButtonValue(char val)
{
	value = val;
}




