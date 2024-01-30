/*
** EPITECH PROJECT, 2024
** Strawberry.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef STRAWBERRY_HPP
#define STRAWBERRY_HPP

#include "ABerry.hpp"

class Strawberry : virtual public ABerry, virtual public AFruit {
public:
    Strawberry();
    ~Strawberry();

    void peel() override {
        _peeled = true;
    }
};

#endif //STRAWBERRY_HPP