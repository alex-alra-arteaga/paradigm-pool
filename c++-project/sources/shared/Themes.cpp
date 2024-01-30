#include "../../include/shared/Themes.hpp"

Themes::themes Themes::_currentTheme = Themes::themes::DEFAULT;

const Themes::themes *Themes::getTheme()
{
    return &_currentTheme;
}

void Themes::setTheme(const Themes::themes &theme)
{
    _currentTheme = theme;
}
