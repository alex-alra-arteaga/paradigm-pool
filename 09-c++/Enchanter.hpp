/*
** EPITECH PROJECT, 2024
** Enchanter.hpp
** File description:
** Paradigm Seminar, ex02
*/

#include "Peasant.hpp"

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

class Enchanter : virtual public Peasant {
    public:
        Enchanter(std::string const &_name, int _power);
        ~Enchanter();

        int attack();
        int special();
        void rest();
        void damage(int damage);
};

#endif /* !ENCHANTER_HPP_ */