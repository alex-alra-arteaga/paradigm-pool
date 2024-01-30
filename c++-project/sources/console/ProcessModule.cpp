#include "../../include/console/ProcessModule.hpp"
#include <ncurses.h>

ProcessModule::ProcessModule(int x, int y, int w, int h, ITheme *theme)
    : _theme(theme), _process(Process())
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

void ProcessModule::draw()
{
    int x, y;
    getmaxyx(_win, y, x);

    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_border, COLOR_PAIR(_theme->getText()));
    mvwprintw(_border, 0, 3, getName());
    wattroff(_border, COLOR_PAIR(_theme->getText()));

    auto maxLines = y - 2;
    auto processes = _process.getProcess(maxLines);

    for (int i = 0; i < processes.size(); i++) {
        wattron(_win, COLOR_PAIR(_theme->getText()));
        mvwprintw(_win, i + 1, 1, "%s", processes[i].c_str());
        wattroff(_win, COLOR_PAIR(_theme->getText()));
    }

    wrefresh(_border);
    wrefresh(_win);
}

void ProcessModule::resize(int w, int h)
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

const char *ProcessModule::getName() const
{
    return _name;
}

bool ProcessModule::bigEnough(int w, int h) const
{
    return w >= 20 && h >= 4;
}

void ProcessModule::fallBack() const
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

void ProcessModule::setTheme(ITheme *theme)
{
    _theme = theme;
}

bool ProcessModule::isDisabled() const
{
    return _disabled;
}

void ProcessModule::setDisabled(bool disabled)
{
    _disabled = disabled;
}

const char *ProcessModule::getId() const
{
    return _id;
}

ProcessModule::~ProcessModule()
{
    delwin(_win);
    delwin(_border);
}
