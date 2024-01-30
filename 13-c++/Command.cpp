/*
** EPITECH PROJECT, 2024
** Command.hpp
** File description:
** Paradigm Seminar, ex04
*/

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function)
{
    if (_map.find(name) == _map.end())
        _map[name] = function;
    else
        throw Command::Error("Already registered command");
}

void Command::executeCommand(const std::string &name)
{
    if (_map.find(name) != _map.end())
        _map[name]();
    else
        throw Command::Error("Unknow command");
}