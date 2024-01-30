/*
** EPITECH PROJECT, 2024
** Stack.cpp
** File description:
** Paradigm Seminar, ex02
*/

#include "Stack.hpp"

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop()
{
    if (_stack.empty())
        throw Stack::Error(EMPTY_STACK);
    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top() const
{
    if (_stack.empty())
        throw Stack::Error(EMPTY_STACK);
    return _stack.top();
}

void Stack::add()
{
    if (_stack.size() < 2)
        throw Stack::Error(MISSING_OPERAND);
    double a = pop();
    double b = pop();
    push(a + b);
}

void Stack::sub()
{
    if (_stack.size() < 2)
        throw Stack::Error(MISSING_OPERAND);
    double a = pop();
    double b = pop();
    push(a - b);
}

void Stack::mul()
{
    if (_stack.size() < 2)
        throw Stack::Error(MISSING_OPERAND);
    double a = pop();
    double b = pop();
    push(a * b);
}

void Stack::div()
{
    if (_stack.size() < 2)
        throw Stack::Error(MISSING_OPERAND);
    double a = pop();
    double b = pop();
    push(a / b);
}

const char *Stack::Error::what() const noexcept
{
    return lastError == EMPTY_STACK ? "Empty stack" : lastError ==  MISSING_OPERAND ? "Not enough operands" : "";
}