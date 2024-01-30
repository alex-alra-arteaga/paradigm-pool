#include "../../include/console/RamModule.hpp"
#include <ncurses.h>
#include "infoware/system.hpp"

RAMModule::RAMModule(int x, int y, int w, int h, ITheme *theme) : _theme(theme)
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

void RAMModule::draw()
{
    int x, y;
    getmaxyx(_win, y, x);

    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_border, COLOR_PAIR(_theme->getText()));
    mvwprintw(_border, 0, 3, getName());
    wattroff(_border, COLOR_PAIR(_theme->getText()));

    auto physicalAvailable = iware::system::memory().physical_available;
    auto physicalTotal = iware::system::memory().physical_total;

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 1, 1, "RAM: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 1, 7, "%.2f%% ",
        (physicalTotal - physicalAvailable) * 100.0 / physicalTotal);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 2, 1, "Used: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 2, 7, "%.2fGB ",
        (physicalTotal - physicalAvailable) / 1024.0 / 1024.0 / 1024.0);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 3, 1, "Free: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(
        _win, 3, 7, "%.2fGB ", physicalAvailable / 1024.0 / 1024.0 / 1024.0);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    auto virtualAvailable = iware::system::memory().virtual_available;
    auto virtualTotal = iware::system::memory().virtual_total;

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 1, 39, "vRAM: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 1, 45, "%.2f%% ",
        (virtualTotal - virtualAvailable) * 100.0 / virtualTotal);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 2, 39, "Used: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 2, 45, "%.2fGB ",
        (virtualTotal - virtualAvailable) / 1024.0 / 1024.0 / 1024.0);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 3, 39, "Free: ");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(
        _win, 3, 45, "%.2fGB ", virtualAvailable / 1024.0 / 1024.0 / 1024.0);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    {
        int bar_size = x - 3;
        int percentage =
            (physicalTotal - physicalAvailable) * 100.0 / physicalTotal;
        attron(COLOR_PAIR(_theme->getBorder()));
        mvwprintw(_win, y - 4, 1, "[");
        for (int i = 0; i < bar_size; i++) {
            auto character = "|";
            if (i > bar_size / 4 && percentage < 20) {
                character = ".";
            } else if (i > bar_size / 2 && percentage < 50) {
                character = ".";
            } else if (i > bar_size * 3 / 4 && percentage < 80) {
                character = ".";
            }
            mvwprintw(_win, y - 4, i + 2, character);
        }
        mvwprintw(_win, y - 4, x - 2, "]");
        mvwprintw(_win, y - 4, (x / 2) - 3, " %d%% ", percentage);
        attroff(COLOR_PAIR(_theme->getBorder()));
    }

    int bar_size = x - 3;
    int percentage =
        (physicalTotal - physicalAvailable) * 100.0 / physicalTotal;
    attron(COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, y - 2, 1, "[");
    for (int i = 0; i < bar_size; i++) {
        auto character = "|";
        if (i > bar_size / 4 && percentage < 20) {
            character = ".";
        } else if (i > bar_size / 2 && percentage < 50) {
            character = ".";
        } else if (i > bar_size * 3 / 4 && percentage < 80) {
            character = ".";
        }
        mvwprintw(_win, y - 2, i + 2, character);
    }
    mvwprintw(_win, y - 2, x - 2, "]");
    mvwprintw(_win, y - 2, (x / 2) - 3, " %d%% ", percentage);
    attroff(COLOR_PAIR(_theme->getBorder()));

    wrefresh(_border);
    wrefresh(_win);
}

void RAMModule::resize(int w, int h)
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

const char *RAMModule::getName() const
{
    return _name;
}

bool RAMModule::bigEnough(int w, int h) const
{
    return w >= 20 && h >= 4;
}

void RAMModule::fallBack() const
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

void RAMModule::setTheme(ITheme *theme)
{
    _theme = theme;
}

bool RAMModule::isDisabled() const
{
    return _disabled;
}

void RAMModule::setDisabled(bool disabled)
{
    _disabled = disabled;
}

const char *RAMModule::getId() const
{
    return _id;
}

RAMModule::~RAMModule()
{
    delwin(_win);
    delwin(_border);
}
