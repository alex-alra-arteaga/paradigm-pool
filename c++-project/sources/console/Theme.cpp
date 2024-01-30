#include "../../include/console/Theme.hpp"
#include <ncurses.h>

int Theme::BACKGROUND = COLOR_BLACK;
int Theme::TEXT = COLOR_WHITE;
int Theme::BORDER = COLOR_RED;

const int Theme::getBackground() const
{
    return BACKGROUND;
}

const int Theme::getText() const
{
    return TEXT;
}

const int Theme::getBorder() const
{
    return BORDER;
}

void Theme::setBackground(int background)
{
    BACKGROUND = background;
}

void Theme::setText(int color)
{
    TEXT = color;
}

void Theme::setBorder(int color)
{
    BORDER = color;
}

DefaultTheme::DefaultTheme()
{
    setBackground(COLOR_BLACK);
    setText(COLOR_WHITE);
    setBorder(COLOR_RED);
}

DarkTheme::DarkTheme()
{
    setBackground(COLOR_BLACK);
    setText(COLOR_GREEN);
    setBorder(COLOR_WHITE);
}

LightTheme::LightTheme()
{
    setBackground(COLOR_WHITE);
    setText(COLOR_BLACK);
    setBorder(COLOR_MAGENTA);
}
