/*
** EPITECH PROJECT, 2024
** Priest.hpp
** File description:
** Paradigm Seminar, ex03
*/

#include "Enchanter.hpp"

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

class Priest : virtual public Enchanter {
    public:
        Priest(std::string const &_name, int _power);
        ~Priest();

        void rest();
};

#endif /* !PRIEST_HPP_ */