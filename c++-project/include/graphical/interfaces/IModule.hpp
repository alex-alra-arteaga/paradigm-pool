
#ifndef IMODULE_HPP
#define IMODULE_HPP

#include <SFML/Graphics.hpp>
#include "../interfaces/IDisplay.hpp"
#include <iostream>

class IModule {
public:
    virtual ~IModule() = default;

    virtual sf::Vector2f getSize() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::Font *getFont() const = 0;
    virtual size_t getCycles() const = 0;
    virtual IDisplay *getCoreDisplay() const = 0;
    virtual IDisplay *getRamDisplay() const = 0;

    virtual void sumIterations() = 0;
    virtual void emptyIterations() = 0;

    virtual void render(sf::RenderWindow &window) = 0;
};

#endif //IMODULE_HPP