/*
** EPITECH PROJECT, 2024
** Federation.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include "WarpSystem.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->name = name;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << name << " has been finished." << std::endl
    << "It is " << length << " m in length and " << width << " m in width."
    << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;

    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << this->name << ": The core is " <<
              (this->_core->checkReactor()->isStable() ? "stable" : "unstable") <<
              " at the time." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move() {
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (this->_photonTorpedo != 0) {
        this->_photonTorpedo--;
        std::cout << this->name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        if (this->_photonTorpedo == 0)
            std::cout << this->name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    } else
        std::cout << this->name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
    target->setShield(target->getShield() - 50);
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes <= this->_photonTorpedo) {
        this->_photonTorpedo -= torpedoes;
        target->setShield(target->getShield() - 50 * torpedoes);
        std::cout << this->name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        if (this->_photonTorpedo == 0)
            std::cout << this->name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    } else
        std::cout << this->name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    this->_captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->name = name;
    this->_maxWarp = 1;
    this->_home = VULCAN;
    this->_location = this->_home;
    std::cout << "The independent ship " << name << " just finished its construction."
    << std::endl << "It is " << length << " m in length and "
    << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << this->name << ": The core is " <<
              (this->_core->isStable() ? "stable" : "unstable") <<
              " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move() {
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}