#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include "../interfaces/IModule.hpp"
#include "../interfaces/IDisplay.hpp"

#ifndef COREDISPLAY_HPP
#define COREDISPLAY_HPP

class CoreDisplay : virtual public IDisplay {
public:
    CoreDisplay(size_t numDataFrames, std::string xTitle, std::string yTitle, IModule *module);
    ~CoreDisplay();

    void indexLines() override;
    void indexPoints() override;
    void xTitle() override;
    void yTitle() override;
    sf::Vector2f getModuleSize() const override { return _coreModule->getSize(); };
    sf::Vector2f getModulePosition() const override { return _coreModule->getPosition(); }
    bool isBlue() const override { return _isBlue; };

    void setBlue(bool isBlue) override { _isBlue = isBlue; };
    void updateFrame(size_t index, float value) override;
    void emptyDataFrames() override;
    void render(sf::RenderWindow &window) override;

private:
    size_t _numDataFrames;
    std::string _xTitleString;
    std::string _yTitleString;
    sf::Text *_xTitle;
    sf::Text *_yTitle;
    IModule *_coreModule;
    std::array<sf::RectangleShape *, 200> *_dataFrames;
    bool _isBlue = false;
};

#endif //COREDISPLAY_HPP