/*
** EPITECH PROJECT, 2024
** Borg.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "Federation.hpp"
#include "Borg.hpp"
#include "WarpSystem.hpp"
#include <iostream>

Borg::Ship::Ship(int weaponFrequency, short repair)
{
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    this->_weaponFrequency = weaponFrequency;
    this->_repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::checkCore(void)
{
    std::cout << (this->_core->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable()) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move() {
    if (this->_core->checkReactor()->isStable()) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair(void)
{
    if (this->_repair > 0) {
        this->_repair--;
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}