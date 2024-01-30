/*
** EPITECH PROJECT, 2024
** Paladin.hpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Knight.hpp"
#include "Enchanter.hpp"
#include "Priest.hpp"

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

class Paladin : virtual public Knight, virtual public Priest {
    public:
        Paladin(std::string const &_name, int _power);
        ~Paladin();

        int attack();
        int special();
        void rest();
        void damage(int damage);
};

#endif /* !PALADIN_HPP_ */