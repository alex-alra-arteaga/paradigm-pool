#include <ncurses.h>
#include "Battery.hpp"
#include "interfaces/IModule.hpp"
#include "interfaces/ITheme.hpp"

#ifndef BATTERYMODULE_HPP_
    #define BATTERYMODULE_HPP_

class BatteryModule : public Krell::IModule {
  private:
    /* The coordinates of the module */
    int _x;
    int _y;
    /* The size of the module in percentage */
    int _w;
    int _h;
    /* Initial percentage values */
    int _init_w;
    int _init_h;
    /* The name of the module */
    const char *_name = "Battery Module";
    /* The theme of the module */
    ITheme *_theme;
    /* The window and the border of the module */
    WINDOW *_win;
    WINDOW *_border;
    /* Battery information wrapper */
    Battery _battery;
    /* If the module is disabled */
    bool _disabled = false;
    /* The id of the module */
    const char *_id = "battery";

  public:
    BatteryModule() = delete;
    BatteryModule(int x, int y, int w, int h, ITheme *theme);
    ~BatteryModule() override;
    void draw() override;
    const char *getName() const override;
    void resize(int w, int h) override;
    bool bigEnough(int w, int h) const override;
    void fallBack() const override;
    void setTheme(ITheme *theme) override;
    bool isDisabled() const override;
    void setDisabled(bool disabled) override;
    const char * getId() const override;
};

#endif /* !BATTERYMODULE_HPP_ */
