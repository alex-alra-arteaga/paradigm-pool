/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Paradigm Seminar, ex05
*/

#include <iostream>
#include "Toy.hpp"

Toy::Toy(const Toy &other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    _lastError = other._lastError;
}

Toy::Toy(Toy &&other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    _lastError = other._lastError;
    other._name = "";
    other._type = BASIC_TOY;
    other._picture = *(new Picture());
    other._lastError = *(new Error());
}

bool Toy::setAscii(const std::string &file)
{
    if (_picture.getPictureFromFile(file)) {
        return true;
    }
    _lastError = *(new Error(Error::PICTURE));
    return false;
};


void Toy::speak(const std::string statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

bool Toy::speak_es(const std::string)
{
    _lastError = *(new Error(Error::SPEAK));
    return false;
}

Toy &Toy::operator=(const Toy &other)
{
    _name = other._name;
    _type = other._type;
    _picture = other._picture;
    _lastError = other._lastError;
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
