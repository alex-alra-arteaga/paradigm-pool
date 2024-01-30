#include "../../include/console/WindowManager.hpp"
#include <memory>
#include <ncurses.h>
#include <thread>
#include "../../include/console/Theme.hpp"

CWindowManager::CWindowManager()
{
#if (THEME == THEME_DEFAULT)
    _theme = std::make_unique<DefaultTheme>();
    _selectedTheme = 0;
#elif (THEME == THEME_DARK)
    _theme = std::make_unique<DarkTheme>();
    _selectedTheme = 1;
#elif (THEME == THEME_LIGHT)
    _theme = std::make_unique<LightTheme>();
    _selectedTheme = 2;
#endif

    auto win = initscr();
    getmaxyx(win, _y, _x);
    nodelay(win, true);
    keypad(win, true);
    noecho();
    curs_set(0);
    raw();
    start_color();
    init_pair(_theme->getText(), _theme->getText(), _theme->getBackground());
    init_pair(
        _theme->getBorder(), _theme->getBorder(), _theme->getBackground());
}

void CWindowManager::step()
{
    getmaxyx(stdscr, _y, _x);
    for (auto &module : _modules) {
        if (module->bigEnough(_x, _y)) {
            module->draw();
        } else {
            module->fallBack();
        }
    }
}

void CWindowManager::setTheme(ITheme &theme)
{
    _theme = std::unique_ptr<ITheme>(&theme);
}

ITheme &CWindowManager::getTheme()
{
    return *_theme;
}

void CWindowManager::addModule(Krell::IModule &module)
{
    for (auto &m : _modules) {
        if (m->getName() == module.getName()) {
            return;
        }
    }
    _modules.push_back(std::unique_ptr<Krell::IModule>(&module));
}

void CWindowManager::removeModule(const std::string &name)
{
    for (auto &m : _modules) {
        if (m->getName() == name) {
            _modules.erase(_modules.begin());
            return;
        }
    }
}

void CWindowManager::loop()
{
    while (_modules.size() > 0) {
        int ch = getch();
        switch (ch) {
            case 'q': {
                return;
            }
            case 'n': {
                _selectedTheme = (_selectedTheme + 1) % 3;
                std::unique_ptr<ITheme> newTheme;

                switch (_selectedTheme) {
                    case 0: newTheme = std::make_unique<DefaultTheme>(); break;
                    case 1: newTheme = std::make_unique<DarkTheme>(); break;
                    case 2: newTheme = std::make_unique<LightTheme>(); break;
                }

                _theme = std::move(newTheme);

                for (auto &module : _modules) {
                    module->setTheme(_theme.get());
                }

                init_pair(_theme->getText(), _theme->getText(),
                    _theme->getBackground());
                init_pair(_theme->getBorder(), _theme->getBorder(),
                    _theme->getBackground());
                break;
            };
            case KEY_RESIZE: {
                getmaxyx(stdscr, _y, _x);
                for (auto &module : _modules) {
                    module->resize(_x, _y);
                    step();
                    _tick = 0;
                }
                break;
            }
        }
        if (++_tick == 5) {
            step();
            _tick = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

CWindowManager::~CWindowManager()
{
    endwin();
}
