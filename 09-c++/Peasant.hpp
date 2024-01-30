/*
** EPITECH PROJECT, 2024
** Peasant.hpp
** File description:
** Paradigm Seminar, ex00
*/

#include <string>
#include "ICharacter.hpp"

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

class Peasant : virtual public ICharacter {
    public:
        Peasant(std::string const &_name, int _power);
        ~Peasant();

        void setName(std::string _name) { name = _name; };
        void setPower(int _power) { power = std::max(0, std::min(100, _power)); };
        const std::string &getName() const { return name; };
        int getPower() const { return power; };
        int getHp() const { return health; };

        int attack();
        int special();
        void rest();
        void damage(int damage);
    protected:
        std::string name;
        int power;
        int health;
};

#endif /* !PEASANT_HPP_ */