#include "../../include/graphical/CoreModule.hpp"
#include "../../include/graphical/WindowManager.hpp"
#include "../../include/graphical/components/CoreDisplay.hpp"

CoreModule::CoreModule(WindowManager *windowManager)
{
    sf::Vector2f size(600, 170);
    sf::Color borderColor(255, 255, 255, 255);
    _windowManager = windowManager;
    _border = new sf::RectangleShape(size);
    _border->setFillColor(sf::Color::Transparent);
    _border->setOutlineColor(borderColor);
    _border->setOutlineThickness(5);
    _border->setPosition(100, 160);
    _coreDisplay = new CoreDisplay(200, "Cycles", "CPU Usage", this);
    _coreDisplay->xTitle();
    _coreDisplay->yTitle();
}

CoreModule::~CoreModule()
{
    delete _border;
    delete _coreDisplay;
}

void CoreModule::sumIterations()
{
    _validIterations++;
}

void CoreModule::emptyIterations()
{
    _validIterations = 0;
}

void CoreModule::render(sf::RenderWindow &window)
{
    window.draw(*_border);
    _coreDisplay->render(window);
}
