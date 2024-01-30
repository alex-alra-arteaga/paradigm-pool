/*
** EPITECH PROJECT, 2024
** AFruit.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef AFruit_HPP
#define AFruit_HPP

#include "IFruit.hpp"

class AFruit : virtual public IFruit {
public:
    AFruit();
    ~AFruit();

    virtual unsigned int getVitamins() const { return isPeeled() ? _vitamins : 0; };
    virtual std::string getName() const { return _name; };
    virtual bool isPeeled() const { return _peeled; };
    virtual void peel() = 0;

protected:
    std::string _name;
    int _vitamins;
    bool _peeled = false;
};

#endif //AFruit_HPP