#include <iostream>
#include <vector>
#include "../include/graphical/WindowManager.hpp"
#include "../include/console/BatteryModule.hpp"
#include "../include/console/CpuModule.hpp"
#include "../include/console/InfoModule.hpp"
#include "../include/console/ProcessModule.hpp"
#include "../include/console/RamModule.hpp"
#include "../include/console/WindowManager.hpp"

void initConsole(int argc, char **argv)
{
    int y = 0;
    CWindowManager manager;
    std::vector<Krell::IModule *> modules;

#ifdef ENABLE_BATTERY
    modules.push_back(new BatteryModule(0, 0, 100, 20, &manager.getTheme()));
    y += 20;
#endif

#ifdef ENABLE_SYSTEM
    modules.push_back(new InfoModule(0, y, 100, 20, &manager.getTheme()));
    y += 20;
#endif

#ifdef ENABLE_CPU
    modules.push_back(new CpuModule(0, y, 100, 30, &manager.getTheme()));
    y += 27;
#endif

#ifdef ENABLE_RAM
    modules.push_back(new RAMModule(0, y, 50, 35, &manager.getTheme()));
#endif

#ifdef ENABLE_PROCESS
    modules.push_back(new ProcessModule(50, y, 50, 35, &manager.getTheme()));
#endif

    for (int i = 1; i < argc; i++) {
        for (auto &module : modules) {
            if (module->getId() == std::string(argv[i])) {
                module->setDisabled(true);
            }
        }
    }

    for (auto &module : modules) {
        if (!module->isDisabled()) {
            manager.addModule(*module);
        }
    }

    manager.loop();
}

void initGraphical([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    WindowManager windowManager;
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cerr << "Usage: ./MyGKrellm <mode> [...options]" << std::endl;
        return 84;
    }
    auto option = std::string(argv[1]);
    if (option == "-h" || option == "--help") {
        std::cerr << "Usage: ./MyGKrellm <mode> [...options]" << std::endl;
        std::cerr << "Modes:" << std::endl;
        std::cerr << "  console" << std::endl;
        std::cerr << "  graphical" << std::endl;
        std::cerr << "Options:" << std::endl;
        std::cerr << "  -h, --help: Show this menu" << std::endl;
        std::cerr << "  batery: hide the battery in console mode" << std::endl;
        std::cerr << "  system: hide the system info in console mode"
                  << std::endl;
        std::cerr << "  cpu: hide the cpu in console mode" << std::endl;
        std::cerr << "  ram: hide the ram in console mode" << std::endl;
        std::cerr << "  process: hide the process in console mode"
                  << std::endl;
        std::cerr << "Tips:" << std::endl;
        std::cerr << "  press `q` to quit" << std::endl;
        std::cerr << "  press `n` to change theme in console mode"
                  << std::endl;
        return 0;
    }

    if (option != "console" && option != "graphical") {
        std::cerr << "Usage: ./MyGKrellm <mode> [...options]" << std::endl;
        return 84;
    }

    if (option == "console") {
        initConsole(argc, argv);
    } else {
        initGraphical(argc, argv);
    }
}
