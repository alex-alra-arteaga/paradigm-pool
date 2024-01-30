/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** Paradigm Seminar, ex03
*/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

#include <iostream>
#include <string>

template<typename T>
class UniquePointer {
public:
    UniquePointer() : _ptr(nullptr) {};
    UniquePointer(const UniquePointer &other) = delete;
    UniquePointer(UniquePointer &&other) = delete;

    UniquePointer(T *other)
    {
        _ptr = other;
    }
    UniquePointer &operator=(T *other)
    {
        delete _ptr;
        _ptr = other;
        return *this;
    }
    T *operator->() {return _ptr; };
    T &operator*() {return *_ptr; };

    ~UniquePointer()
    {
        delete _ptr;
    }

    void reset(T *other = nullptr) {
        delete _ptr;
        _ptr = other;
    }

    T *get() const { return _ptr; }

    T *&operator->() const { return *_ptr; }

private:
    T *_ptr;
};

#endif //UNIQUEPOINTER_HPP