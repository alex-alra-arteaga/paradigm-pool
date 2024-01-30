/*
** EPITECH PROJECT, 2024
** DirectoryLister.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef DIRECTORYLISTER_HPP
#define DIRECTORYLISTER_HPP

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister();
    explicit DirectoryLister(const std::string &path, bool hidden);
    ~DirectoryLister();

    DirectoryLister(const DirectoryLister &other) = delete;
    DirectoryLister &operator=(const DirectoryLister &other) = delete;

    DirectoryLister(DirectoryLister &&other) noexcept;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

private:
    DIR* dir = nullptr;
    bool _ignoreHidden;
};

#endif //DIRECTORYLISTER_HPP