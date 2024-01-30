/*
** EPITECH PROJECT, 2024
** Orange.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef ORANGE_HPP
#define ORANGE_HPP

#include "ACitrus.hpp"

class Orange : virtual public ACitrus, virtual public AFruit {
public:
    Orange();
    ~Orange();

    void peel() override {
        _peeled = true;
    }
};

#endif //ORANGE_HPP