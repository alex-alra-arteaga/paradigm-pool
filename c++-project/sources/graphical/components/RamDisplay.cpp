#include "../../../include/graphical/components/RamDisplay.hpp"
#include <cmath>

RamDisplay::RamDisplay(size_t numDataFrames, std::string xTitle, std::string yTitle, IModule *module)
{
    _numDataFrames = numDataFrames;
    _xTitleString = xTitle;
    _yTitleString = yTitle;
    _module = module;
    _dataPoints = new std::array<sf::CircleShape *, 40>();
    _lineConnectors = new std::array<sf::RectangleShape *, 40>();
    indexPoints();
    indexLines();
}

RamDisplay::~RamDisplay()
{
    delete _xTitle;
    delete _yTitle;
    for (size_t i = 0; i < _numDataFrames; ++i)
        delete (*_dataPoints)[i];
    delete _dataPoints;
    for (size_t i = 0; i < _numDataFrames; ++i)
        delete (*_lineConnectors)[i];
    delete _lineConnectors;
}

void RamDisplay::indexLines()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    for (size_t i = 0; i < _numDataFrames; i++) {
        sf::Vector2f indexPosition(modulePosition.x + (moduleSize.x / _numDataFrames) * i, 550);

        sf::RectangleShape *lineConnector = new sf::RectangleShape();
        lineConnector->setSize(sf::Vector2f(1, 2));
        lineConnector->setFillColor(sf::Color::White);
        lineConnector->setPosition(indexPosition);
        (*_lineConnectors)[i] = lineConnector;
    }
}

void RamDisplay::indexPoints()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    for (size_t i = 0; i < _numDataFrames; i++) {
        sf::Vector2f indexPosition(modulePosition.x + (moduleSize.x / _numDataFrames) * i, 550);

        sf::CircleShape *dataPoint = new sf::CircleShape();
        dataPoint->setRadius(1);
        dataPoint->setFillColor(sf::Color::White);
        dataPoint->setPosition(indexPosition);
        (*_dataPoints)[i] = dataPoint;
    }
}

void RamDisplay::xTitle()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    sf::Vector2f indexPosition = sf::Vector2f(modulePosition.x + (moduleSize.x / 2) - 30, modulePosition.y + moduleSize.y + 10);

    _xTitle = new sf::Text();
    _xTitle->setString(_xTitleString);
    _xTitle->setPosition(indexPosition);
    _xTitle->setCharacterSize(20);
    _xTitle->setFont(*(_module->getFont()));
    _xTitle->setFillColor(sf::Color::White);
}

void RamDisplay::yTitle()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    sf::Vector2f indexPosition = sf::Vector2f(modulePosition.x - 35, modulePosition.y + (moduleSize.y / 2) + 50);

    _yTitle = new sf::Text();
    _yTitle->setString(_yTitleString);
    _yTitle->setPosition(indexPosition);
    _yTitle->setCharacterSize(20);
    _yTitle->setFont(*(_module->getFont()));
    _yTitle->rotate(270);
    _yTitle->setFillColor(sf::Color::White);
}

void RamDisplay::updatePoints(size_t index, float value) {
    if (index >= _dataPoints->size() || index == 0)
        return;

    sf::Vector2f pos = (*_dataPoints)[index]->getPosition();
    (*_dataPoints)[index]->setPosition(sf::Vector2f(pos.x, 550 - value));
    (*_dataPoints)[index]->setFillColor(isBlue() ? sf::Color::Blue : sf::Color::White);

    sf::Vector2f startPos = (*_dataPoints)[index - 1]->getPosition();
    sf::Vector2f endPos = (*_dataPoints)[index]->getPosition();

    float dx = endPos.x - startPos.x;
    float dy = endPos.y - startPos.y;
    float distance = sqrt(dx * dx + dy * dy);
    float angle = atan2(dy, dx) * 180 / M_PI;

    sf::RectangleShape* connector = (*_lineConnectors)[index - 1];
    connector->setFillColor(isBlue() ? sf::Color::Blue : sf::Color::White);
    connector->setSize(sf::Vector2f(distance, 1));
    connector->setOrigin(0, 0.5f);
    connector->setPosition(startPos);
    connector->setRotation(angle);
}

void RamDisplay::updateFrame(size_t index, float value)
{
    updatePoints(index, value);
}

void RamDisplay::emptyDataFrames()
{
    for (size_t i = 0; i < _numDataFrames; i++) {
        int x = (*_dataPoints)[i]->getPosition().x;
        (*_dataPoints)[i]->setPosition(sf::Vector2f(x, -1));
    }
}


void RamDisplay::render(sf::RenderWindow &window)
{
    window.draw(*_xTitle);
    window.draw(*_yTitle);
    for (size_t i = 0; i < _numDataFrames; i++)
        window.draw((*(*_dataPoints)[i]));
    for (size_t i = 0; i < _numDataFrames; i++)
        window.draw((*(*_lineConnectors)[i]));
}