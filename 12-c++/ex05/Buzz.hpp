/*
** EPITECH PROJECT, 2024
** Buzz.hpp
** File description:
** Paradigm Seminar, ex05
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz() = delete;
        Buzz(std::string _name, std::string _fileName = "buzz.txt") : Toy(BUZZ, _name, _fileName) {};
        ~Buzz() = default;

        void speak(const std::string statement) override;
        bool speak_es(const std::string statement) override;


};

#endif //BUZZ_HPP_