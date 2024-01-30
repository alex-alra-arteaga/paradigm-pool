/*
** EPITECH PROJECT, 2024
** Buzz.hpp
** File description:
** Paradigm Seminar, ex02
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz() = delete;
        Buzz(std::string _name, std::string _fileName = "buzz.txt") : Toy(BUZZ, _name, _fileName) {};
        ~Buzz() = default;
};

#endif //BUZZ_HPP_