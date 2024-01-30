/*
** EPITECH PROJECT, 2024
** FruitBox.hpp
** File description:
** Paradigm Seminar, ex01
*/

#ifndef FRUITBOX_HPP
#define FRUITBOX_HPP

#include "IFruit.hpp"
#include <deque>
#include <iostream>

class FruitBox {
    public:
        FruitBox(unsigned int size);
        FruitBox(const FruitBox &other) = delete;
        FruitBox &operator=(const FruitBox &other) = delete;
        ~FruitBox();
        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *f);
        IFruit *popFruit();

        std::deque<IFruit *> _queue;
        unsigned int _size;
};

std::ostream &operator<<(std::ostream &os, FruitBox const &box);

#endif //FRUITBOX_HPP