/*
** EPITECH PROJECT, 2024
** List.cpp
** File description:
** Paradigm Seminar, ex03
*/

#include "List.hpp"

List::List()
{
    _list = std::list<IObject *>();
}

List::~List()
{
    if (!_list.empty())
        clear();
}

List &List::operator=(const List &other)
{
    if (this == &other)
        return *this;
    clear();
    for (auto &elem : other._list)
        _list.push_back(elem);
    return *this;
}

bool List::empty() const
{
    return _list.empty();
}

std::size_t List::size() const
{
    return _list.size();
}

IObject *&List::front()
{
    if (_list.empty())
        throw InvalidOperationException();
    return _list.front();
}

IObject *List::front() const
{
    if (_list.empty())
        throw InvalidOperationException();
    return _list.front();
}

IObject *&List::back()
{
    if (_list.empty())
        throw InvalidOperationException();
    return _list.back();
}

IObject *List::back() const
{
    if (_list.empty())
        throw InvalidOperationException();
    return _list.back();
}

void List::pushBack(IObject *obj)
{
    _list.push_back(obj);
}

void List::pushFront(IObject *obj)
{
    _list.push_front(obj);
}

void List::popFront()
{
    if (_list.empty())
        throw InvalidOperationException();
    delete _list.front();
    _list.pop_front();
}

void List::popBack()
{
    if (_list.empty())
        throw InvalidOperationException();
    delete _list.back();
    _list.pop_back();
}

void List::clear()
{
    for (auto &elem : _list)
        delete elem;
    _list.clear();
}

void List::forEach(void (*function)(IObject *obj))
{
    for (auto &elem : _list)
        function(elem);
}

void touch(IObject* object)
{
    if (object)
        object->touch();
}
