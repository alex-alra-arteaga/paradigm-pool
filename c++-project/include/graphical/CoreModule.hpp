#include <SFML/Graphics.hpp>
#include "./interfaces/IModule.hpp"
#include "./components/CoreDisplay.hpp"
#include "./WindowManager.hpp"
#include <string>

#ifndef COREMODULE_HPP
#define COREMODULE_HPP

class CoreModule : virtual public IModule {
public:
    CoreModule(WindowManager *windowManager);
    ~CoreModule();

    sf::Vector2f getSize() const { return _border->getSize(); };
    sf::Vector2f getPosition() const { return _border->getPosition(); };
    sf::Font *getFont() const { return _windowManager->getFont(); };
    size_t getCycles() const { return _validIterations; };
    CoreDisplay *getCoreDisplay() const { return _coreDisplay; };
    IDisplay *getRamDisplay() const { return nullptr; };

    void sumIterations();
    void emptyIterations();

    void render(sf::RenderWindow &window);


private:
    WindowManager *_windowManager;
    sf::RectangleShape *_border;
    size_t _validIterations = 0;
    CoreDisplay *_coreDisplay;
};

#endif //WINDOWMANAGER_HPP