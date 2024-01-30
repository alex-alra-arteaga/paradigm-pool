/*
** EPITECH PROJECT, 2024
** BorgQueen.hpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
    };
    class Ship;
};

namespace Borg {
    class Ship;
    class BorgQueen {
    public:
        BorgQueen();
        // ~BorgQueen();

        bool (Borg::Ship::*movePtr)(Destination);
        void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
        void (Borg::Ship::*destroyPtr)(Federation::Ship *);

        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
};