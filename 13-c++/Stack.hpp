/*
** EPITECH PROJECT, 2024
** Stack.hpp
** File description:
** Paradigm Seminar, ex02
*/

#ifndef STACK_HPP
#define STACK_HPP

#include <exception>
#include <stack>
#include <iostream>

enum ErrorType {
    UNKNOWN,
    EMPTY_STACK,
    MISSING_OPERAND,
};

class Stack {
public:
    Stack() = default;
    ~Stack() = default;
    void push(double value);
    double pop();
    double top() const;

    void add();
    void sub();
    void mul();
    void div();

    class Error : public std::exception {
    public:
        Error() = delete;
        Error(ErrorType error) : lastError(error) {}
        ~Error() = default;
        const char *what() const noexcept override;

        ErrorType lastError;
    };

private:
    std::stack<double> _stack;
};

#endif //STACK_HPP