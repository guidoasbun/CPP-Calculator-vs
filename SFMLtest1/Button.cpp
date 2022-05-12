#include "Button.h"

Button::Button()
{
	
}

Button::~Button()
{

}

sf::RectangleShape Button::getButtonShape()
{
	return button;
}

void Button::setButtonShape(float xCoordinates, float yCoordinates)
{
	button.setPosition(xCoordinates, yCoordinates);
}

