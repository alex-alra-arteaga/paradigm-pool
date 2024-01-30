/*
** EPITECH PROJECT, 2024
** KoalaBot.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"
#include <iostream>

KoalaBot::KoalaBot(std::string serial) : _serial(serial), _arms(new Arms()), _legs(new Legs()), _head(new Head()) {}

void KoalaBot::swapParts(Arms &arms)
{
    Arms *tmp = this->_arms;
    this->_arms = &arms;
    arms = *tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs *tmp = this->_legs;
    this->_legs = &legs;
    legs = *tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head *tmp = this->_head;
    this->_head = &head;
    head = *tmp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms->informations();
    this->_legs->informations();
    this->_head->informations();
}

bool KoalaBot::status() const
{
    return (this->_arms->isFunctional() && this->_legs->isFunctional() && this->_head->isFunctional());
}
