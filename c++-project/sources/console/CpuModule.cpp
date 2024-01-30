#include "../../include/console/CpuModule.hpp"
#include <ncurses.h>
#include "infoware/cpu.hpp"

CpuModule::CpuModule(int x, int y, int w, int h, ITheme *theme)
    : _theme(theme), _cpu(CPU())
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

void CpuModule::draw()
{
    int x, y;
    getmaxyx(_win, y, x);

    auto data = _cpu.collectCpuUsagePerCore();

    wattron(_border, COLOR_PAIR(_theme->getBorder()));
    box(_border, 0, 0);
    wattroff(_border, COLOR_PAIR(_theme->getBorder()));
    wattron(_border, COLOR_PAIR(_theme->getText()));
    mvwprintw(_border, 0, 3, "%s", iware::cpu::model_name().c_str());
    wattroff(_border, COLOR_PAIR(_theme->getText()));

    for (int i = 0; i < data.size(); i++) {
        wattron(_border, COLOR_PAIR(_theme->getBorder()));
        mvwprintw(_win, i / 4 + 1, (i % 4) * (x / 4) + 2, "%.2f%% ", data[i]);
        wattroff(_border, COLOR_PAIR(_theme->getBorder()));
        wattron(_win, COLOR_PAIR(_theme->getText()));
        mvwprintw(_win, i / 4 + 1, (i % 4) * (x / 4) + 8, "[");
        bool flag = false;
        for (int j = 0; j < 10; j++) {
            if (j < data[i] / 10) {
                wprintw(_win, "=");
            } else {
                if (!flag) {
                    wprintw(_win, ">");
                    flag = true;
                } else {
                    wprintw(_win, " ");
                }
            }
        }
        wprintw(_win, "]");
        wattroff(_win, COLOR_PAIR(_theme->getText()));
    }

    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 8, 2, "Manufacturer:");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 8, 16, "%s", iware::cpu::vendor_id().c_str());
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 7, 2, "Logical CPUs:");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 7, 16, "%d", iware::cpu::quantities().logical);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));
    wattron(_win, COLOR_PAIR(_theme->getText()));
    mvwprintw(_win, 6, 2, "CPU packages:");
    wattroff(_win, COLOR_PAIR(_theme->getText()));
    wattron(_win, COLOR_PAIR(_theme->getBorder()));
    mvwprintw(_win, 6, 16, "%d", iware::cpu::quantities().packages);
    wattroff(_win, COLOR_PAIR(_theme->getBorder()));

    wrefresh(_border);
    wrefresh(_win);
}

void CpuModule::resize(int w, int h)
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

const char *CpuModule::getName() const
{
    return _name;
}

bool CpuModule::bigEnough(int w, int h) const
{
    return w >= 20 && h >= 4;
}

void CpuModule::fallBack() const
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

void CpuModule::setTheme(ITheme *theme)
{
    _theme = theme;
}

bool CpuModule::isDisabled() const
{
    return _disabled;
}

void CpuModule::setDisabled(bool disabled)
{
    _disabled = disabled;
}

const char *CpuModule::getId() const
{
    return _id;
}

CpuModule::~CpuModule()
{
    delwin(_win);
    delwin(_border);
}
