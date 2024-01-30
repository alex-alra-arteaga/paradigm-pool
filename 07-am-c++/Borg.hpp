/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex01
*/

#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
    }
    class Ship;
}

namespace WarpSystem {
    class Core;
}

namespace Borg
{
    class Ship {
    public:
        Ship(int weaponFrequency = 20, short repair = 3);
        // ~Ship();
        void setupCore(WarpSystem::Core *core) { this->_core = core; }
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        int getShield() { return _shield; }
        void setShield(int shield) { _shield = shield; }
        int getWeaponFrequency(void) { return _weaponFrequency; }
        void setWeaponFrequency(int frequency) { _weaponFrequency = frequency; }
        short getRepair(void) { return _repair; }
        void setRepair(short repair) { _repair = repair; }
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair(void);


    private:
        int _side = 300;
        short _maxWarp = 9;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
        int _shield;
        int _weaponFrequency;
        short _repair;
    };
    class BorgQueen;
}