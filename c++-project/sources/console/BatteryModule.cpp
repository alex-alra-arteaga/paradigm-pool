#include "../../include/console/BatteryModule.hpp"
#include <ncurses.h>

BatteryModule::BatteryModule(int x, int y, int w, int h, ITheme *theme)
    : _theme(theme), _battery(Battery())
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

void BatteryModule::draw()
{
    int x, y;
    getmaxyx(_win, y, x);

    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_border, COLOR_PAIR(_theme->getText()));
    mvwprintw(_border, 0, 3, getName());
    wattroff(_border, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 1, x / 2 - 9, "%s",
        _battery.isCharging() ? "battery charging..." : "battery emptying...");
    wattroff(_win, COLOR_PAIR(_theme->getText()));

    int percentage = _battery.getPercentage();
    int bar_size = ((x / 2) * 100) / 100;

    attron(COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, y / 2, x / 2 - (bar_size / 2), "[");
    for (int i = 0; i < bar_size; i++) {
        auto character = "|";
        if (i > bar_size / 4 && percentage < 20) {
            character = ".";
        } else if (i > bar_size / 2 && percentage < 50) {
            character = ".";
        } else if (i > bar_size * 3 / 4 && percentage < 80) {
            character = ".";
        }
        mvwprintw(_win, y / 2, x / 2 - (bar_size / 2) + i + 1, character);
    }
    mvwprintw(_win, y / 2, x / 2 + (bar_size / 2) + 1, "]");
    mvwprintw(_win, y / 2, (x / 2) - 3, " %d%% ", percentage);
    attroff(COLOR_PAIR(_theme->getBorder()));

    wrefresh(_border);
    wrefresh(_win);
}

void BatteryModule::resize(int w, int h)
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

const char *BatteryModule::getName() const
{
    return _name;
}

bool BatteryModule::bigEnough(int w, int h) const
{
    return w >= 20 && h >= 4;
}

void BatteryModule::fallBack() const
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

void BatteryModule::setTheme(ITheme *theme)
{
    _theme = theme;
}

bool BatteryModule::isDisabled() const
{
    return _disabled;
}

void BatteryModule::setDisabled(bool disabled)
{
    _disabled = disabled;
}

const char *BatteryModule::getId() const
{
    return _id;
}

BatteryModule::~BatteryModule()
{
    delwin(_win);
    delwin(_border);
}
