/*
** EPITECH PROJECT, 2024
** IFruit.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef IFRUIT_HPP
#define IFRUIT_HPP

#include <string>

class IFruit {
    public:
        virtual ~IFruit() = default;
        // returns the number of vitamins in the fruit when the fruit is peeled, 0 otherwise
        virtual unsigned int getVitamins() const = 0;
        virtual  std::string getName() const = 0;
        //  returns true if the fruit is peeled
        virtual bool isPeeled() const = 0;
        // peel the fruit, a fruit is not peeled by default
        virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);

#endif //IFRUIT_HPP