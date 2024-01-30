/*
** EPITECH PROJECT, 2024
** ICharacter.hpp
** File description:
** Paradigm Seminar, ex05
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>

class ICharacter {
    public:
        virtual ~ICharacter() = default;
        virtual std::string const &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
};

#endif /* !ICHARACTER_HPP_ */