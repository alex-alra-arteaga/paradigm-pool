/*
** EPITECH PROJECT, 2024
** SafeDirectoryLister.hpp
** File description:
** Paradigm Seminar, ex01
*/

#ifndef SAFEDIRECTORYLISTER_HPP
#define SAFEDIRECTORYLISTER_HPP

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class SafeDirectoryLister : virtual public IDirectoryLister {
public:
    SafeDirectoryLister();
    explicit SafeDirectoryLister(const std::string &path, bool hidden);
    ~SafeDirectoryLister();

    SafeDirectoryLister(const SafeDirectoryLister &other) = delete;
    SafeDirectoryLister &operator=(const SafeDirectoryLister &other) = delete;

    SafeDirectoryLister(SafeDirectoryLister &&other) = delete;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

private:
    DIR* dir = nullptr;
    bool _ignoreHidden;
};

#endif //SAFEDIRECTORYLISTER_HPP