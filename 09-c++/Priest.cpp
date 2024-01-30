/*
** EPITECH PROJECT, 2024
** Priest.cpp
** File description:
** Paradigm Seminar, ex03
*/

#include "Priest.hpp"
#include <iostream>
#include <algorithm>

Priest::Priest(std::string const &_name, int _power) : Peasant(_name, _power), Enchanter(_name, _power)
{
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return;
    }
    power = std::min(100, power + 100);
    health = std::min(100, health + 100);
    std::cout << name << " prays." << std::endl;
}
