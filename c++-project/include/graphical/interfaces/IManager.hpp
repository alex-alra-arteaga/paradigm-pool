#include <SFML/Graphics.hpp>
#include <iostream>

class IManager {
public:
    virtual ~IManager() = default;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void destroy() = 0;
};