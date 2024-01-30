/*
** EPITECH PROJECT, 2024
** Buzz.cpp
** File description:
** Paradigm Seminar, ex05
*/

#include "Buzz.hpp"
#include <iostream>

void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ: " << getName() << " \"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string statement)
{
    std::cout << "BUZZ: " << getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return true;
}