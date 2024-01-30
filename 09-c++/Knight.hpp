/*
** EPITECH PROJECT, 2024
** Knight.hpp
** File description:
** Paradigm Seminar, ex01
*/

#include <string>
#include "Peasant.hpp"

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

class Knight : virtual public Peasant {
    public:
        Knight(std::string const &_name, int _power);
        ~Knight();

        int attack();
        int special();
        void rest();
        void damage(int damage);
};

#endif /* !KNIGHT_HPP_ */