#include "ITheme.hpp"

#ifndef CIMODULE_HPP_
    #define CIMODULE_HPP_

class CIModule {
  public:
    virtual ~CIModule() = default;
    /* The draw function is called every frame */
    virtual void draw() = 0;
    /* The resize function is called when the window is resized */
    virtual void resize(int w, int h) = 0;
    /* The getName function is used to identify the module */
    virtual const char *getName() const = 0;
    /* The unique module identifier */
    virtual const char *getId() const = 0;
    /* If the modules should NOT be loaded */
    virtual bool isDisabled() const = 0;
    /* Set the module to disabled */
    virtual void setDisabled(bool disabled) = 0;
    /* The bigEnough function is used to know if the module can be resized */
    virtual bool bigEnough(int w, int h) const = 0;
    /* The fallBack function is used when the screen is too small */
    virtual void fallBack() const = 0;
    /* The setTheme function is used to change the theme of the module */
    virtual void setTheme(ITheme *theme) = 0;
};

namespace Krell
{
    using IModule = CIModule;
};

#endif /* !CIMODULE_HPP_ */
