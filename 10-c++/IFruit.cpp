/*
** EPITECH PROJECT, 2024
** IFruit.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "IFruit.hpp"

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    os << std::string("[name: \"") << fruit.getName() << std::string("\", vitamins: ") << std::to_string(fruit.getVitamins()) << std::string(", peeled: ") << std::string(fruit.isPeeled() ? "true]" : "false]");
    return os;
}