/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Paradigm Seminar, ex02
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

Toy &Toy::operator=(const Toy &other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    return *this;
}