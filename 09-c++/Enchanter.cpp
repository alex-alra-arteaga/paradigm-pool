/*
** EPITECH PROJECT, 2024
** Enchanter.cpp
** File description:
** Paradigm Seminar, ex02
*/

#include "Enchanter.hpp"
#include <iostream>
#include <algorithm>

Enchanter::Enchanter(std::string const &_name, int _power) : Peasant(_name, _power)
{
    std::cout << name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return 0;
    }
    if (power < 10) {
        std::cout << name << " is out of power." << std::endl;
        return 0;
    }
    std::cout << name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (power < 50) {
        std::cout << name << " is out of power." << std::endl;
        return 0;
    } else if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return 0;
    } else {
        std::cout << name << " casts a fireball." << std::endl;
        power -= 50;
        return 99;
    }
}

void Enchanter::rest()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return;
    }
    power = std::min(100, power + 100);
    std::cout << name << " meditates." << std::endl;
}

void Enchanter::damage(int damage)
{
    health = std::max(health - damage, 0);
    if (health == 0)
        std::cout << name << " is out of combat." << std::endl;
    else
        std::cout << name << " takes " << damage << " damage." << std::endl;
}
