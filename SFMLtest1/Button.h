#pragma once

#include "Calculator.h"

class Button
{
private:
	sf::RectangleShape buttonShape;
	char operation;

public:
	Button();
	virtual ~Button();

	//Getters
	sf::RectangleShape getButtonShape();

	

	//Setters
	void setButtonShape(float xCoordinates, float yCoordinates);

	

};

