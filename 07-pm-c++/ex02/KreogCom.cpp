/*
** EPITECH PROJECT, 2024
** KreogCom.cpp
** File description:
** Paradigm Seminar, ex02
*/

#include "KreogCom.hpp"
#include <iostream>

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial), x(x), y(y)
{
    this->next = nullptr;
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);
    newCom->next = this->next;
    this->next = newCom;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = this->next;
    this->next = this->next->next;
    delete tmp;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->x << " " << this->y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->next;
    while (tmp) {
        tmp->ping();
        tmp = tmp->next;
    }
    this->ping();
}

int main()
{
    KreogCom k(42, 42, 101010);
    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
    k.removeCom();
    k.removeCom();
    return 0;
}