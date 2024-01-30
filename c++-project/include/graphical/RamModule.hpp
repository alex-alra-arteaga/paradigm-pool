#include <SFML/Graphics.hpp>
#include "./interfaces/IModule.hpp"
#include "./components/RamDisplay.hpp"
#include "./WindowManager.hpp"
#include <string>
#include <memory>

#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

class RamModule : virtual public IModule {
public:
    RamModule(WindowManager *windowManager);
    ~RamModule();

    sf::Vector2f getSize() const override { return _border->getSize(); };
    sf::Vector2f getPosition() const override { return _border->getPosition(); };
    sf::Font *getFont() const override { return _windowManager->getFont(); };
    size_t getCycles() const override { return _validIterations; };
    IDisplay *getCoreDisplay() const override { return nullptr; };
    IDisplay* getRamDisplay() const override { return _ramDisplay.get(); }

    void sumIterations() override;
    void emptyIterations() override;

    void render(sf::RenderWindow &window) override;


private:
    WindowManager *_windowManager;
    sf::RectangleShape *_border;
    std::unique_ptr<IDisplay> _ramDisplay;
    size_t _validIterations = 0;
};

#endif //RAMMODULE_HPP