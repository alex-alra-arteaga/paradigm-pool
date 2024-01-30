/*
** EPITECH PROJECT, 2024
** BorgQueen.hpp
** File description:
** Paradigm Seminar, ex00
*/

#include <string>

#include "Destination.hpp"

namespace WarpSystem {
    class Core;
}

namespace Borg {
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain;
        class Ensign;

        class Ship {
        public:
            Ship(int length = 289, int width = 132, std::string name = "Entreprise", short maxWarp = 6, int torpedo = 0);
            // ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            void promote(Captain *captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield() { return _shield; };
            void setShield(int shield) { _shield = shield; };
            int getTorpedo() { return _photonTorpedo; };
            void setTorpedo(int torpedo) { _photonTorpedo = torpedo; };
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);

        private:
            int _length;
            int _width;
            std::string name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield ;
            int _photonTorpedo ;
        };

        class Captain {
        public:
            Captain(std::string name);
            // ~Captain();
            std::string getName(void) { return _name; };
            int getAge(void) { return _age; };
            void setAge(int age) { _age = age; };

        private:
            std::string _name;
            int _age;
        };

        class Ensign {
        public:
            explicit Ensign(std::string name);
            // ~Ensign();

        private:
            std::string _name;
        };

        class Admiral;
    }

    class Ship {
    public:
        Ship(int length, int width, std::string name);
        // ~Ship();
        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
        WarpSystem::Core *getCore() { return this->_core; }

    private:
        int _length;
        int _width;
        std::string name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };
};