/*
** EPITECH PROJECT, 2024
** Skat.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Skat.hpp"
#include <iostream>

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stimPaks(stimPaks) {}

Skat::~Skat() {}

void Skat::shareStimPaks(int number, int stock)
{
    if (number > this->_stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        std::cout << "Keep the change." << std::endl;
        this->_stimPaks -= number;
        Skat::stock += number;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    } else {
        this->_stimPaks += number;
    }
}

void Skat::useStimPaks()
{
    if (this->_stimPaks) {
        this->_stimPaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status() const
{
    std::cout << "Soldier " << Skat::name() << " reporting " << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}

int Skat::stock = 0;
