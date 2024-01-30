/*
** EPITECH PROJECT, 2024
** UniquePointer.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "UniquePointer.hpp"
#include <iostream>

UniquePointer::UniquePointer(IObject &other) : _ptr(&other)
{
}

UniquePointer::UniquePointer(IObject *other) : _ptr(other)
{
}

UniquePointer &UniquePointer::operator=(IObject *other)
{
    delete _ptr;
    _ptr = other;
    return *this;
}

UniquePointer &UniquePointer::operator=(IObject &other)
{
    delete _ptr;
    _ptr = &other;
    return *this;
}

UniquePointer::~UniquePointer()
{
    delete _ptr;
}
