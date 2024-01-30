#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include "../interfaces/IModule.hpp"
#include "../interfaces/IDisplay.hpp"

#ifndef RAMDISPLAY_HPP
#define RAMDISPLAY_HPP

class RamDisplay : virtual public IDisplay {
public:
    RamDisplay(size_t numDataFrames, std::string xTitle, std::string yTitle, IModule *module);
    ~RamDisplay();

    void indexLines() override;
    void indexPoints() override;
    void xTitle() override;
    void yTitle() override;
    sf::Vector2f getModuleSize() const override { return _module->getSize(); };
    sf::Vector2f getModulePosition() const override { return _module->getPosition(); }
    bool isBlue() const override { return _isBlue; };

    void setBlue(bool isBlue) override { _isBlue = isBlue; };
    void updateFrame(size_t index, float value) override;
    void updatePoints(size_t index, float value);
    void updateLine(size_t index, float value);
    void emptyDataFrames() override;
    void render(sf::RenderWindow &window) override;

private:
    size_t _numDataFrames;
    std::string _xTitleString;
    std::string _yTitleString;
    sf::Text *_xTitle;
    sf::Text *_yTitle;
    IModule *_module;
    std::array<sf::RectangleShape *, 40> *_lineConnectors;
    std::array<sf::CircleShape *, 40> *_dataPoints;
    bool _isBlue = false;
};

#endif //RAMDISPLAY_HPP