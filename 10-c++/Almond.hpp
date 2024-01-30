/*
** EPITECH PROJECT, 2024
** Almond.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef ALMOND_HPP
#define ALMOND_HPP

#include "ANut.hpp"

class Almond : virtual public ANut, virtual public AFruit {
public:
    Almond();
    ~Almond();

    void peel() override {
        _peeled = true;
    }
};

#endif //ALMOND_HPP