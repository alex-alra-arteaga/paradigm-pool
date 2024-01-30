/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** Paradigm Seminar, ex05
*/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

#include <iostream>

template<typename T>
class SharedPointer {
public:
    SharedPointer(T *ptr = nullptr) : _ptr(ptr) { _count = new std::size_t(!_ptr ? 0 : 1); };

    SharedPointer(const SharedPointer &other)
            : _ptr(other._ptr), _count(other._count)
    {
        if (_count)
            ++(*_count);
    }

    SharedPointer(SharedPointer &&other)
    {
        _ptr = other._ptr;
        _count = other._count;
        other._ptr = nullptr;
        other._count = nullptr;

    };

    T *operator->() {return _ptr; };
    T &operator*() {return *_ptr; };

    ~SharedPointer()
    {
        if (_count && --(*_count) == 0) {
            delete _count;
            delete _ptr;
        }
    }

    void reset(T *other = nullptr)
    {
        if (_count && --(*_count) == 0) {
            delete _count;
            delete _ptr;
        }
        _ptr = other;
        _count = new std::size_t(!_ptr ? 0 : 1);
    }

    T *get() const { return _ptr; }

    T &operator*() const {
        if (!_ptr)
            throw std::exception();
        else
            return *_ptr;
    }

    T *&operator->() const { return _ptr; }

    SharedPointer &operator=(const SharedPointer &other)
    {
        if (_count && --(*_count) == 0) {
            delete _count;
            delete _ptr;
        }
        _ptr = other._ptr;
        _count = other._count;
        if (_count)
            ++(*_count);
        return *this;
    }

    SharedPointer &operator=(SharedPointer &&other)
    {
        if (_count && --(*_count) == 0) {
            delete _count;
            delete _ptr;
        }
        _ptr = other._ptr;
        _count = other._count;
        other._ptr = nullptr;
        other._count = nullptr;
        return *this;
    }

    SharedPointer &operator=(T *ptr)
    {
        reset(ptr);
        return *this;
    }

private:
    T *_ptr = nullptr;
    std::size_t *_count = nullptr;
};


#endif //UNIQUEPOINTER_HPP