/*
** EPITECH PROJECT, 2024
** Parts.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "Parts.hpp"
#include <iostream>

Arms::Arms(std::string serial, bool functional) : _serial(serial), _functional(functional) {}
Head::Head(std::string serial, bool functional) : _serial(serial), _functional(functional) {}
Legs::Legs(std::string serial, bool functional) : _serial(serial), _functional(functional) {}

void Arms::informations() const
{
    std::cout << "\t[PARTS] " << "Arms " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Legs::informations() const
{
    std::cout << "\t[PARTS] " << "Legs " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}

void Head::informations() const
{
    std::cout << "\t[PARTS] " << "Head " << this->_serial << " status : " << (this->_functional ? "OK" : "KO") << std::endl;
}
