#include <SFML/Graphics.hpp>
#include <string>
#include "./interfaces/IModule.hpp"
#include "./interfaces/IDisplay.hpp"
#include "../shared/components/CPUData.hpp"
#include "../shared/components/MemoryData.hpp"

#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

    // dynamically handles window resizing
    void resizeEvents();
    void setFrameRate(unsigned int frameRate);
    void initFont(const std::string &fontPath);
    void setText(sf::Text *, const std::string &text, size_t size, sf::Color color = sf::Color::White, sf::Vector2f position = sf::Vector2f(0, 0));
    void setBackground(const std::string &backgroundPath);
    sf::Font *getFont() const { return _font; };

    void render(sf::RenderWindow &window);

private:
    sf::Font *_font;
    IModule *_coreModule;
    IModule *_ramModule;
    sf::Texture _bgTexture;
    sf::Text *_modelText;
    sf::Text *_cpuValueText;
    sf::Text *_memoryValueText;
    sf::Text *_totalMemoryText;
    sf::Text *_usedMemoryText;
    sf::Text *_freeMemoryText;
    sf::Text *_coreCountText;
    sf::Sprite *_background;
    CPUData *_cpuData;
    MemoryData *_memoryData;
};

#endif //WINDOWMANAGER_HPP