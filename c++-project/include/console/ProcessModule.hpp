#include <ncurses.h>
#include "Process.hpp"
#include "interfaces/IModule.hpp"
#include "interfaces/ITheme.hpp"

#ifndef PROCESS_MODULE_HPP_
    #define PROCESS_MODULE_HPP_

class ProcessModule : public Krell::IModule {
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
    const char *_name = "Process Module";
    /* The theme of the module */
    ITheme *_theme;
    /* The window and the border of the module */
    WINDOW *_win;
    WINDOW *_border;
    /* Battery information wrapper */
    Process _process;
    /* If the module is disabled */
    bool _disabled = false;
    /* The id of the module */
    const char *_id = "process";

  public:
    ProcessModule() = delete;
    ProcessModule(int x, int y, int w, int h, ITheme *theme);
    ~ProcessModule() override;
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

#endif /* !PROCESS_MODULE_HPP_ */
