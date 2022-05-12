#include "Button.h"

sf::RectangleShape Button::getButtonShape()
{
	return buttonShape;
}

void Button::setButtonShape(float xCoordinates, float yCoordinates)
{
	buttonShape.setPosition(xCoordinates, yCoordinates);
}

