/*
** EPITECH PROJECT, 2024
** List.hpp
** File description:
** Paradigm Seminar, ex03
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include "IObject.hpp"
#include <iostream>
#include <string>
#include <list>
#include <exception>

class List {
public:
    List();
    ~List();
    List(const List &other) = delete;
    List(List &&other) = delete;

    List &operator=(const List &other);

    bool empty() const;
    std::size_t size() const;
    IObject *&front();
    IObject *front() const;
    IObject *&back();
    IObject *back() const;
    void pushBack(IObject *obj);
    void pushFront(IObject *obj);
    void popFront();
    void popBack();
    void clear();
    void forEach(void (*function)(IObject *obj));

    class InvalidOperationException : public std::exception
    {
        public:
            InvalidOperationException() {};
            ~InvalidOperationException() = default;

            const char *what() const noexcept override { return "Invalid operation"; };
    };

private:
    std::list<IObject *> _list;
};

#endif //LIST_HPP_