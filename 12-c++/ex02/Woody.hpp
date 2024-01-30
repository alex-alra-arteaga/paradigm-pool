/*
** EPITECH PROJECT, 2024
** Woody.hpp
** File description:
** Paradigm Seminar, ex02
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
public:
    Woody() = delete;
    Woody(std::string _name, std::string _fileName = "woody.txt") : Toy(WOODY, _name, _fileName) {};
    ~Woody() = default;
};

#endif //WOODY_HPP_