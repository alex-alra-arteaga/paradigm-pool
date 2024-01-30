/*
** EPITECH PROJECT, 2024
** Algorithm.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <string>
#include <iostream>

template<typename T>
concept HasLessThanOperator = requires(T a, T b)
{
    { a < b } -> std::convertible_to<bool>;
};

template<HasLessThanOperator T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<HasLessThanOperator T>
T min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

template<HasLessThanOperator T>
T max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}

template<HasLessThanOperator T>
T clamp(const T& value, const T& minVal, const T& maxVal)
{
    return (value < minVal) ? minVal : (maxVal < value) ? maxVal : value;
}

#endif //ALGORITHM_HPP