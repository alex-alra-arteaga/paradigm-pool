/*
** EPITECH PROJECT, 2024
** Peasant.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Peasant.hpp"
#include <iostream>
#include <algorithm>

Peasant::Peasant(const std::string &_name, int _power) : name(_name), health(100) {
    setPower(_power);
    std::cout << name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << name << " is back to his crops." << std::endl;
}

int Peasant::attack()
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
    std::cout << name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (health == 0)
        std::cout << name << " is out of combat." << std::endl;
    else
        std::cout << name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (health == 0) {
        std::cout << name << " is out of combat." << std::endl;
        return;
    }
    power = std::min(100, power + 30);
    std::cout << name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    health = std::max(health - damage, 0);
    if (health == 0)
        std::cout << name << " is out of combat." << std::endl;
    else
        std::cout << name << " takes " << damage << " damage." << std::endl;
}

