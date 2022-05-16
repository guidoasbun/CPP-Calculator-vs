//
// Created by Guido Asbun on 5/7/22.
//

#include "Calculator.h"

//Private functions
void Calculator::initVariables()
{
    window = nullptr;

    //Calculator Logic
}

void Calculator::initWindow()
{
    videoMode.height = 700;
    videoMode.width = 600;

    window = new sf::RenderWindow(videoMode, "CPP Calculator", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(60);
}

void Calculator::initFonts()
{
    font.loadFromFile("Fonts/Roboto-Bold.ttf");
    //    if (font.loadFromFile("Fonts/Roboto-Bold.ttf"))
    //        std::cout << "ERROR::CALCULATOR::INITFONTS::Failed to load font" << "\n";
}

void Calculator::initDisplayText()
{
    uiText.setFont(font);
    uiText.setCharacterSize(60);
    uiText.setFillColor(sf::Color::White);
    uiText.setString("NONE");
    uiText.setPosition(20.f, 35.f);
}

void Calculator::initDisplay()
{
    display.setPosition(0.f, 0.f);
    display.setSize(sf::Vector2f(600.f, 160.f));
    display.setFillColor(sf::Color::Black);
}

void Calculator::initOperators()
{
    std::vector<char> opFunction ={ '+', '-', '*', '/' };
    float const yCoordinate = 180.f;
	float xCoordinate = 30.f;

    for (auto op_function : opFunction)
    {
        button.setButtonPosition(xCoordinate, yCoordinate);
        button.setButtonSize(120.f, 80.f);
        button.setFillColor(79,79,79);
        button.setButtonValue(op_function);
        opButton.push_back(button);
        xCoordinate += 140.f;
    }
}

void Calculator::initNumbers()
{
    std::vector<char> nums = {'7', '8', '9', '4', '5', '6', '1', '2', '3', '.', '0', 'c'};
    float yCoordinate = 180.f;
    float xCoordinate = 30.f;

    
    for (int i = 0; i < 12; ++i)
    {
        if (i % 3 == 0)
        {
            xCoordinate = 30.f;
            yCoordinate += 105.f;
        }

		button.setButtonPosition(xCoordinate, yCoordinate);
		button.setButtonSize(120.f, 80.f);
	    button.setFillColor(150, 150, 150);
        button.setButtonValue(nums[i]);
        if (i == 11)
        {
            button.setFillColor(190, 38, 38);
        }
		numButton.push_back(button);
        xCoordinate += 140.f;
    }
}

void Calculator::initEquals()
{
    float const yCoordinates = 280.f;
    float const xCoordinates = 450.f;
    equals.setButtonPosition(xCoordinates, yCoordinates);
    equals.setButtonSize(120.f, 400.f);
    equals.setFillColor(50, 161, 50);
    equals.setButtonValue('=');
}

//Constructors / Destructors
Calculator::Calculator()
{
    initVariables();
    initWindow();
    initDisplayText();

    initFonts();
    initDisplay();
    initOperators();
    initNumbers();
    initEquals();
}

Calculator::~Calculator()
{
    delete window;
}

//Accessors
const bool Calculator::running() const
{
    return window->isOpen();
}

//Functions
void Calculator::pollEvents()
{
    //Event polling
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                window->close();
            break;
            default:
                break;
        }
    }
}

//Update Functions
void Calculator::updateMousePosition()
{
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

void Calculator::updateDisplayText()
{
    std::stringstream ss;

    ss << "0.0";

    uiText.setString(ss.str());
}

void Calculator::update()
{
    pollEvents();
    updateMousePosition();
    updateDisplayText();
}

//Render functions
void Calculator::renderDisplayText(sf::RenderTarget& target)
{
    target.draw(uiText);
}

void Calculator::renderDisplay(sf::RenderTarget& target)
{
    target.draw(display);
}

void Calculator::renderOperators(sf::RenderTarget& target)
{
    for (auto& e : opButton)
    {
        target.draw(e.getButtonShape());
    }
}

void Calculator::renderNumbers(sf::RenderTarget& target)
{
    for (auto& e : numButton)
    {
        target.draw(e.getButtonShape());
    }
}

void Calculator::renderEquals(sf::RenderTarget& target)
{
    target.draw(equals.getButtonShape());
}

void Calculator::render()
{

    //Sets window with light grey background
    window->clear(sf::Color(204, 204, 204));

    //Draw game objects

    renderDisplay(*window);
    renderDisplayText(*window);
    renderOperators(*window);
    renderNumbers(*window);
    renderEquals(*window);

    window->display();
}