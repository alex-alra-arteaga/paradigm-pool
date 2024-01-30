/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Paradigm Seminar, ex04
*/

#include <iostream>
#include "Toy.hpp"

Toy::Toy(const Toy &other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
}

Toy::Toy(Toy &&other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    other._name = "";
    other._type = BASIC_TOY;
    other._picture = *(new Picture());
}

void Toy::speak(const std::string statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator=(const Toy &other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    return *this;
}

std::ostream &operator<<(std::ostream &s, const Toy &toy)
{
    s << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return s;
}

Toy &Toy::operator<<(const std::string &str)
{
    _picture.setData(str);
    return *this;
}
