/*
** EPITECH PROJECT, 2024
** IDirectoryLister.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef IDIRECTORYLISTER_HPP
#define IDIRECTORYLISTER_HPP

#include <string>
#include <cstring>
#include <exception>

class IDirectoryLister {
public:
    virtual ~IDirectoryLister() = default;

    virtual bool open(const std::string &path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception
    {
        public:
            OpenFailureException() {};
            ~OpenFailureException() = default;

            const char *what() const noexcept override { return std::strerror(errno); };
    };

    class NoMoreFileException : public std::exception
    {
        public:
            NoMoreFileException() {};
            ~NoMoreFileException() = default;

            const char *what() const noexcept override { return "End of stream"; };
    };
};

#endif //IDIRECTORYLISTER_HPP