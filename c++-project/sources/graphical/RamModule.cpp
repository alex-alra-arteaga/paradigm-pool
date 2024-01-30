#include "../../include/graphical/RamModule.hpp"
#include "../../include/graphical/WindowManager.hpp"

RamModule::RamModule(WindowManager *windowManager)
{
    sf::Vector2f size(600, 170);
    sf::Color borderColor(255, 255, 255, 255);
    _windowManager = windowManager;
    _border = new sf::RectangleShape(size);
    _border->setFillColor(sf::Color::Transparent);
    _border->setOutlineColor(borderColor);
    _border->setOutlineThickness(5);
    _border->setPosition(100, 380);
    _ramDisplay = std::make_unique<RamDisplay>(40, "Cycles", "RAM Usage", this);
    _ramDisplay->xTitle();
    _ramDisplay->yTitle();
}

RamModule::~RamModule()
{
    delete _border;
}

void RamModule::sumIterations()
{
    _validIterations++;
}

void RamModule::emptyIterations()
{
    _validIterations = 0;
}

void RamModule::render(sf::RenderWindow &window)
{
    window.draw(*_border);
    _ramDisplay->render(window);
}
