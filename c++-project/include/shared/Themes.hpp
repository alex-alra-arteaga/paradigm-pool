#ifndef THEMES_H_
#define THEMES_H_

#include <cstdint>

class Themes {
  public:
    enum themes {
        DEFAULT,
        ONE_DARK,
    };

    union Color {
        uint32_t hex;
        struct {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        } rgba;
    };

    class Default {
      public:
        constexpr static const Color _text = {0xffffff};
        constexpr static const Color _accent = {0x00ffff};
        constexpr static const Color _background = {0x000000};
    };
    class OneDark {
      public:
        constexpr static const Color _text = {0xabb2bf};
        constexpr static const Color _accent = {0xe06c75};
        constexpr static const Color _background = {0x282c34};
    };

    static const themes *getTheme();
    static void setTheme(const themes &theme);

  private:
    static themes _currentTheme;
};

#endif /* THEMES_H_ */
