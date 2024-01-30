/*
** EPITECH PROJECT, 2024
** FruitBox.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "FruitBox.hpp"
#include <iostream>
#include <algorithm>

FruitBox::FruitBox(unsigned int size)
{
    _queue = std::deque<IFruit *>();
    _size = size;
}

FruitBox::~FruitBox()
{
    std::for_each(_queue.begin(), _queue.end(), [](IFruit *fruit) {
        delete fruit;
    });
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    return _queue.size();
}

bool FruitBox::pushFruit(IFruit *f)
{
    if (_queue.size() < _size) {
        _queue.push_back(f);
        return true;
    }
    return false;
}

IFruit *FruitBox::popFruit()
{
    if (_queue.empty())
        return nullptr;
    IFruit *tmp = _queue.front();
    _queue.pop_front();
    return tmp;
}

std::ostream &operator<<(std::ostream &os, FruitBox const &box) {
    os << "[";
    bool first = true;
    for (const auto& fruit : box._queue) {
        if (!first) {
            os << ", ";
        }
        os << *fruit;
        first = false;
    }
    os << "]";
    return os;
}
