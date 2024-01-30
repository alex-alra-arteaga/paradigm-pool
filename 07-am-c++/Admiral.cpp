/*
** EPITECH PROJECT, 2024
** Admiral.cpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Admiral.hpp"
#include <string>
#include <iostream>
#include "Federation.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    this->_name = name;
    std::cout << "Admiral " << name << " ready for action." << std::endl;
}

void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
    this->firePtr = &Federation::Starfleet::Ship::fire;
    (ship->*firePtr)(target);
}

bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    this->movePtr = &Federation::Starfleet::Ship::move;
    return (ship->*movePtr)(dest);
}