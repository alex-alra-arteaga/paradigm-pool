/*
** EPITECH PROJECT, 2024
** Lemon.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef LEMON_HPP
#define LEMON_HPP

#include "ACitrus.hpp"

class Lemon : virtual public ACitrus, virtual public AFruit {
public:
    Lemon();
    ~Lemon();

    void peel() override {
        _peeled = true;
    }
};

#endif //LEMON_HPP