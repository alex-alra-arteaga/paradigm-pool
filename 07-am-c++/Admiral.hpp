/*
** EPITECH PROJECT, 2024
** Admiral.hpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Destination.hpp"
#include <string>

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ensign;
        class Ship;

        class Admiral {
        public:
            Admiral(std::string name);
            // ~Admiral();
            bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
            void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *target);
            void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
            bool move(Federation::Starfleet::Ship *ship, Destination dest);

        private:
            std::string _name;
        };
    }
    class Ship;
}