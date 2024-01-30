// This should handle all the available modules
// This should handle creating animations (only visual mode)
// This should arrange the modules in the correct order

#include "../../include/graphical/WindowManager.hpp"
#include "../../include/graphical/CoreModule.hpp"
#include "../../include/graphical/RamModule.hpp"

WindowManager::WindowManager()
{
    try {
        sf::RenderWindow App(sf::VideoMode(820, 1080), "RUSH3");
        // Relative to `build/` directory
        setBackground("../assets/media/future_frame.png");
        initFont("../assets/fonts/bmonofont-i18n.ttf");
        _coreModule = new CoreModule(this);
        _ramModule = new RamModule(this);
        _cpuData = new CPUData();
        _memoryData = new MemoryData();
        std::string model = _cpuData->getCPUModelFromLscpu();
        int coreCount = _cpuData->getCoreCount();
        float _valueCpu = _cpuData->calculateCurrentCpuAvgUsage();
        float _valueRam = _memoryData->getMemoryUsagePercentage();
        unsigned long totalMemory = _memoryData->getTotalMemory();
        unsigned long usedMemory = _memoryData->getUsedMemory();
        unsigned long freeMemory = _memoryData->getFreeMemory();
        _modelText = new sf::Text();
        setText(_modelText, model, 20, sf::Color::White, sf::Vector2f(-150, 100));
        _cpuValueText = new sf::Text();
        setText(_cpuValueText, "CPU: " + std::to_string(_valueCpu) + " MHz", 20, sf::Color::White, sf::Vector2f(100, 600));
        _memoryValueText = new sf::Text();
        setText(_memoryValueText, "RAM: " + std::to_string(_valueRam) + " MBytes", 20, sf::Color::White, sf::Vector2f(100, 650));
        _totalMemoryText = new sf::Text();
        setText(_totalMemoryText, "Total Memory: " + std::to_string(totalMemory) + " Kbytes", 20, sf::Color::White, sf::Vector2f(100, 700));
        _usedMemoryText = new sf::Text();
        setText(_usedMemoryText, "Used Memory: " + std::to_string(usedMemory) + " Kbytes", 20, sf::Color::White, sf::Vector2f(100, 750));
        _freeMemoryText = new sf::Text();
        setText(_freeMemoryText, "Free Memory: " + std::to_string(freeMemory) + " Kbytes", 20, sf::Color::White, sf::Vector2f(100, 800));
        _coreCountText = new sf::Text();
        setText(_coreCountText, "Core Count: " + std::to_string(coreCount), 20, sf::Color::White, sf::Vector2f(100, 850));

        sf::Clock clockCpu;
        sf::Clock clockRam;
        while (App.isOpen()) {
            sf::Time elapsed = clockCpu.getElapsedTime();
            sf::Time elapsedRam = clockRam.getElapsedTime();
            if (elapsed.asSeconds() >= 0.1f) {
                clockCpu.restart();
                size_t cycleCpu = _coreModule->getCycles();
                size_t cycleRam = _ramModule->getCycles();
                float valueCpu = _cpuData->calculateCurrentCpuAvgUsage();
                float valueRam = _memoryData->getMemoryUsagePercentage();
                _coreModule->getCoreDisplay()->updateFrame(cycleCpu, valueCpu / 10);
                _coreModule->sumIterations();
                _cpuValueText->setString("CPU: " + std::to_string(valueCpu) + " MHz");
                _memoryValueText->setString("RAM: " + std::to_string(valueRam) + " MBytes");
                if (elapsedRam.asSeconds() >= 0.5f) {
                    clockRam.restart();
                    _ramModule->getRamDisplay()->updateFrame(cycleRam, valueRam / 10);
                    _ramModule->sumIterations();
                }
                if (cycleCpu == 199) {
                    _coreModule->emptyIterations();
                    _coreModule->getCoreDisplay()->setBlue(!_coreModule->getCoreDisplay()->isBlue());
                    _ramModule->emptyIterations();
                    _ramModule->getRamDisplay()->setBlue(!_ramModule->getRamDisplay()->isBlue());
                }
            }
            sf::Event Event;
            App.clear();
            while (App.pollEvent(Event)) {
                if (Event.type == sf::Event::Closed)
                    App.close();
            }
            render(App);
            App.display();
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

WindowManager::~WindowManager()
{
    delete _font;
    delete _coreModule;
    delete _ramModule;
    delete _background;
    delete _modelText;
    delete _cpuValueText;
    delete _memoryValueText;
    delete _totalMemoryText;
    delete _usedMemoryText;
    delete _freeMemoryText;
    delete _coreCountText;
    delete _cpuData;
    delete _memoryData;
}

void WindowManager::initFont(const std::string &fontPath)
{
    _font = new sf::Font();
    if (!_font->loadFromFile(fontPath))
        throw std::runtime_error("Error: Font not found");
}

void WindowManager::setText(sf::Text *ref,const std::string &text, size_t size, sf::Color color, sf::Vector2f position)
{
    ref->setFont(*_font);
    ref->setString(text);
    ref->setCharacterSize(size);
    ref->setFillColor(color);
    ref->setPosition(position);
}

void WindowManager::setBackground(const std::string &backgroundPath)
{
    _bgTexture.setSmooth(true);
    if (!_bgTexture.loadFromFile(backgroundPath))
        throw std::runtime_error("Error: Background not found");
    _background = new sf::Sprite();
    _background->setTexture(_bgTexture);
    _background->setPosition(-100, -80);
}

void WindowManager::render(sf::RenderWindow &window)
{
    window.draw(*_background);
    window.draw(*_modelText);
    window.draw(*_cpuValueText);
    window.draw(*_memoryValueText);
    window.draw(*_totalMemoryText);
    window.draw(*_usedMemoryText);
    window.draw(*_freeMemoryText);
    window.draw(*_coreCountText);
    _coreModule->render(window);
    _ramModule->render(window);
}