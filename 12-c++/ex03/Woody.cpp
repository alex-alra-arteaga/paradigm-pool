/*
** EPITECH PROJECT, 2024
** Woody.cpp
** File description:
** Paradigm Seminar, ex03
*/

#include "Woody.hpp"
#include <iostream>

void Woody::speak(const std::string statement)
{
    std::cout << "WOODY: " << getName() << " \"" << statement << "\"" << std::endl;
}