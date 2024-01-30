/*
** EPITECH PROJECT, 2024
** Array.hpp
** File description:
** Paradigm Seminar, ex01
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <functional>

template<typename T, std::size_t N>
class Array {
public:
    Array() :  _arr(), _size(N) {};
    Array(Array const &array) = default;
    ~Array() = default;
    Array &operator=(Array const &array);

    // modifier
    T &operator[](std::size_t index) {
        if (index >= N) throw std::out_of_range("Out of range");
        return _arr[index];
    }
    // viewer
    const T &operator[](std::size_t index) const {
        if (index >= N) throw std::out_of_range("Out of range");
        return _arr[index];
    }
    std::size_t size() const { return _size; };
    // std::function is a function pointer, takes a reference to T, which is
    // the type of the array, and returns void (placeholder for any type)
    void forEach(const std::function<void(const T&)>&task) const
    {
        for (std::size_t i = 0; i < _size; i++) {
            task(_arr[i]);
        }
    }

    template<typename U> //        return (param &) float (const int &)
    Array<U, N> convert(const std::function<U(const T &)>&converter) const
    {
        Array<U, N> newArray;
        for (std::size_t i = 0; i < N; i++)
            newArray[i] = converter(_arr[i]);
        return newArray;
    }

private:
    T _arr[N];
    std::size_t _size;
};

template<typename T, std::size_t N>
std::ostream &operator<<(std::ostream &s, const Array<T, N> &arr) {
    s << "[";
    for (std::size_t i = 0; i < N; ++i) {
        s << arr[i];
        if (i < N - 1) s << ", ";
    }
    s << "]";
    return s;
}

#endif //ARRAY_HPP
