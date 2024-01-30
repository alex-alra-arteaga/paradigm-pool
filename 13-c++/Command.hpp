/*
** EPITECH PROJECT, 2024
** Command.hpp
** File description:
** Paradigm Seminar, ex04
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>
#include <functional>
#include <exception>
#include <string>
#include "Stack.hpp"

class Command {
public:
    Command() = default;
    ~Command() = default;

    void registerCommand(const std::string &name, const std::function<void()>&function);
    void executeCommand(const std::string &name);

    class Error : public std::exception {
    public:
        Error() = default;
        ~Error() = default;
        Error(const std::string &message) : _message(message) {};
        const char *what() const noexcept override { return _message.c_str(); };

    private:
        std::string _message;
    };

private:
    std::map<std::string, std::function<void()>> _map;
};

#endif //COMMAND_HPP