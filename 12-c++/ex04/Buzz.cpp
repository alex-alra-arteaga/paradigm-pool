/*
** EPITECH PROJECT, 2024
** Buzz.cpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Buzz.hpp"
#include <iostream>

void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
}
