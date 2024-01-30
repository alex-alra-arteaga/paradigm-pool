#include "ITheme.hpp"

#ifndef CIMANAGER_HPP_
    #define CIMANAGER_HPP_

class CIManager {
  public:
    virtual ~CIManager() = default;
    virtual void step() = 0;
    virtual void setTheme(ITheme &theme) = 0;
    virtual ITheme &getTheme() = 0;
    virtual void loop() = 0;
};

namespace Krell {
  using IDisplay = CIManager;
}

#endif /* !CIMANAGER_HPP_ */
