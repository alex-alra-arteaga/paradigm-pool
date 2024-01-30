#include <memory>
#include <ncurses.h>
#include <vector>
#include "interfaces/IManager.hpp"
#include "interfaces/IModule.hpp"
#include "interfaces/ITheme.hpp"

#ifndef WINDOWMANAGER_HPP_
    #define WINDOWMANAGER_HPP_

class CWindowManager : public Krell::IDisplay {
  private:
    int _tick = 0;
    int _selectedTheme = 0;
    std::unique_ptr<ITheme> _theme;
    std::vector<std::unique_ptr<Krell::IModule>> _modules;

  public:
    int _x;
    int _y;
    CWindowManager();
    ~CWindowManager() override;
    void step() override;
    void setTheme(ITheme &theme) override;
    ITheme &getTheme() override;
    void addModule(Krell::IModule &module);
    void removeModule(const std::string &name);
    void loop() override;
};

#endif /* !WINDOWMANAGER_HPP_ */
