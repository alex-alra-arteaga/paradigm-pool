#include "../../../include/graphical/components/CoreDisplay.hpp"

CoreDisplay::CoreDisplay(size_t numDataFrames, std::string xTitle, std::string yTitle, IModule *module)
{
    _numDataFrames = numDataFrames;
    _xTitleString = xTitle;
    _yTitleString = yTitle;
    _coreModule = module;
    _dataFrames = new std::array<sf::RectangleShape *, 200>();
    indexLines();
}

CoreDisplay::~CoreDisplay()
{
    if (_dataFrames != nullptr) {
        for (size_t i = 0; i < _numDataFrames; ++i)
            delete (*_dataFrames)[i];
        delete _dataFrames;
        _dataFrames = nullptr;
    }
    delete _xTitle;
    delete _yTitle;
}


void CoreDisplay::indexLines()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    for (size_t i = 0; i < _numDataFrames; i++) {
        sf::Vector2f indexPosition(modulePosition.x + (moduleSize.x / _numDataFrames) * i, modulePosition.y + moduleSize.y);
        sf::RectangleShape *dataFrame = new sf::RectangleShape(sf::Vector2f(2, -1));
        dataFrame->setFillColor(sf::Color::White);
        dataFrame->setPosition(indexPosition);
        (*_dataFrames)[i] = dataFrame;
    }
}

void CoreDisplay::indexPoints()
{
}

void CoreDisplay::xTitle()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    sf::Vector2f indexPosition = sf::Vector2f(modulePosition.x + (moduleSize.x / 2) - 30, modulePosition.y + moduleSize.y + 10);

    _xTitle = new sf::Text();
    _xTitle->setString(_xTitleString);
    _xTitle->setPosition(indexPosition);
    _xTitle->setCharacterSize(20);
    _xTitle->setFont(*(_coreModule->getFont()));
    _xTitle->setFillColor(sf::Color::White);
}

void CoreDisplay::yTitle()
{
    sf::Vector2f modulePosition = getModulePosition();
    sf::Vector2f moduleSize = getModuleSize();
    sf::Vector2f indexPosition = sf::Vector2f(modulePosition.x - 35, modulePosition.y + (moduleSize.y / 2) + 50);

    _yTitle = new sf::Text();
    _yTitle->setString(_yTitleString);
    _yTitle->setPosition(indexPosition);
    _yTitle->setCharacterSize(20);
    _yTitle->setFont(*(_coreModule->getFont()));
    _yTitle->rotate(270);
    _yTitle->setFillColor(sf::Color::White);
}

void CoreDisplay::updateFrame(size_t index, float value)
{
    if (isBlue())
        (*_dataFrames)[index]->setFillColor(sf::Color::Blue);
    else
        (*_dataFrames)[index]->setFillColor(sf::Color::White);
    (*_dataFrames)[index]->setSize(sf::Vector2f(2, -value));
}

void CoreDisplay::emptyDataFrames()
{
    for (size_t i = 0; i < _numDataFrames; i++) {
        (*_dataFrames)[i]->setSize(sf::Vector2f(2, -1));
    }
}

void CoreDisplay::render(sf::RenderWindow &window)
{
    window.draw(*_xTitle);
    window.draw(*_yTitle);
    for (size_t i = 0; i < _numDataFrames; i++) {
        window.draw((*(*_dataFrames)[i]));
    }
}