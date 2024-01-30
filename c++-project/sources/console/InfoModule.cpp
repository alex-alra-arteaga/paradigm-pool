#include "../../include/console/InfoModule.hpp"
#include <ncurses.h>

InfoModule::InfoModule(int x, int y, int w, int h, ITheme *theme)
    : _theme(theme), _info(Info())
{
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);
    _init_h = y_max;
    _init_w = x_max;
    _h = (h * y_max) / 100;
    _w = (w * x_max) / 100;
    _x = (x * x_max) / 100;
    _y = (y * y_max) / 100;
    _win = newwin(_h - 2, _w - 2, _y + 1, _x + 1);
    _border = newwin(_h, _w, _y, _x);
}

void InfoModule::draw()
{
#if defined(__APPLE__) || defined(__MACH__)

    int x, y;
    getmaxyx(_win, y, x);

    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_border, COLOR_PAIR(_theme->getText()));
    mvwprintw(_border, 0, 3, getName());
    wattroff(_border, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 1, 1, "User: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 1, 9, "%s", _info.getUsername().c_str());
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 2, 1, "Host: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 2, 9, "%s", _info.getHostname().c_str());
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 3, 1, "OS: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 3, 9, "%s", _info.getOS().c_str());
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 4, 1, "Kernel: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 4, 9, "%s", _info.getKernel().c_str());
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    time_t now = time(0);
    char *dt = ctime(&now);
    mvwprintw(_win, 1, x - 1 - strlen(dt), "%s", dt);

    wrefresh(_border);
    wrefresh(_win);
#endif
}

void InfoModule::resize(int w, int h)
{
    wclear(_win);
    wclear(_border);
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);
    _h = (h * y_max) / 100;
    _w = (w * x_max) / 100;
    _x = (w * x_max) / 100;
    _y = (h * y_max) / 100;
    draw();
}

const char *InfoModule::getName() const
{
    return _name;
}

bool InfoModule::bigEnough(int w, int h) const
{
    return w >= 20 && h >= 4;
}

void InfoModule::fallBack() const
{
    int x, y;
    getmaxyx(_win, y, x);
    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, y / 2, x / 2 - 4, "too small ¯\\_(ツ)_/¯");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wrefresh(_win);
    wrefresh(_border);
}

void InfoModule::setTheme(ITheme *theme)
{
    _theme = theme;
}

bool InfoModule::isDisabled() const
{
    return _disabled;
}

void InfoModule::setDisabled(bool disabled)
{
    _disabled = disabled;
}

const char *InfoModule::getId() const
{
    return _id;
}

InfoModule::~InfoModule()
{
    delwin(_win);
    delwin(_border);
}
