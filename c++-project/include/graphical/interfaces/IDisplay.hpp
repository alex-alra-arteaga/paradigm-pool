#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <SFML/Graphics.hpp>
#include <string>

class IDisplay {
public:
    virtual ~IDisplay() {}

    virtual void indexLines() = 0;
    virtual void indexPoints() = 0;
    virtual void xTitle() = 0;
    virtual void yTitle() = 0;
    virtual sf::Vector2f getModuleSize() const = 0;
    virtual sf::Vector2f getModulePosition() const = 0;
    virtual bool isBlue() const = 0;

    virtual void setBlue(bool isBlue) = 0;
    virtual void updateFrame(size_t index, float value) = 0;
    virtual void emptyDataFrames() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};

#endif //IDISPLAY_HPP
