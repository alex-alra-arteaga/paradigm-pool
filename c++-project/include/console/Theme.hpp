#include "interfaces/ITheme.hpp"

#ifndef THEME_HPP_
    #define THEME_HPP_

    #define THEME_DEFAULT 0
    #define THEME_DARK    1
    #define THEME_LIGHT   2

class Theme : public ITheme {
  protected:
    static int BACKGROUND;
    static int TEXT;
    static int BORDER;

  public:
    const int getBackground() const override;
    const int getText() const override;
    const int getBorder() const override;
    void setBackground(int background) override;
    void setText(int color) override;
    void setBorder(int color) override;
};

class DefaultTheme : public Theme {
  public:
    DefaultTheme();
    ~DefaultTheme() = default;
};

class DarkTheme : public Theme {
  public:
    DarkTheme();
    ~DarkTheme() = default;
};

class LightTheme : public Theme {
  public:
    LightTheme();
    ~LightTheme() = default;
};

#endif /* !THEME_HPP_ */
