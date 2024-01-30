/*
** EPITECH PROJECT, 2024
** Knight.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "Knight.hpp"
#include <iostream>
#include <algorithm>

Knight::Knight(std::string const &_name, int _power) : Peasant(_name, _power)
{
    std::cout << name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return 0;
    }
    if (power < 10) {
        std::cout << name << " is out of power." << std::endl;
        return 0;
    }
    power -= 10;
    std::cout << name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return 0;
    } else if (power < 30) {
        std::cout << name << " is out of power." << std::endl;
        return 0;
    } else {
        std::cout << name << " impales his enemy." << std::endl;
        power -= 30;
        return 50;
    }
}

void Knight::rest()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return;
    }
    power = std::min(100, power + 50);
    std::cout << name << " eats." << std::endl;
}

void Knight::damage(int damage)
{
    health = std::max(health - damage, 0);
    if (health == 0)
        std::cout << name << " is out of combat." << std::endl;
    else
        std::cout << name << " takes " << damage << " damage." << std::endl;
}
