/*
** EPITECH PROJECT, 2024
** Paladin.cpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(std::string const &_name, int _power) : Peasant(_name, _power), Knight(_name, _power), Enchanter(_name, _power), Priest(_name, _power)
{
    std::cout << name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return Paladin::Knight::attack();
}

int Paladin::special()
{
    return Paladin::Enchanter::special();
}

void Paladin::rest()
{
    return Paladin::Priest::rest();
}

void Paladin::damage(int damage)
{
    return Paladin::Priest::damage(damage);
}
