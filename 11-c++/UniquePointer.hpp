/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

#include <iostream>
#include <string>
#include "IObject.hpp"

class UniquePointer {
public:
    UniquePointer() : _ptr(nullptr) {};
    UniquePointer(const UniquePointer &other) = delete;
    UniquePointer(UniquePointer &&other) = delete;

    UniquePointer(IObject *other);
    UniquePointer(IObject &other);
    UniquePointer &operator=(IObject *other);
    UniquePointer &operator=(IObject &other);

    IObject *operator->() {return _ptr; };
    IObject &operator*() {return *_ptr; };

    ~UniquePointer();

    void touch() {
        if (_ptr)
            _ptr->touch();
    }

    void reset(IObject *other = nullptr) {
        delete _ptr;
        _ptr = other;
    }

    void swap(UniquePointer &other) {
        IObject *tmp = _ptr;
        _ptr = other._ptr;
        other._ptr = tmp;
    }

private:
    IObject *_ptr;
};

#endif //UNIQUEPOINTER_HPP