/*
** EPITECH PROJECT, 2024
** SafeDirectoryLister.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "SafeDirectoryLister.hpp"
#include <dirent.h>
#include <exception>

SafeDirectoryLister::SafeDirectoryLister() : _ignoreHidden(false)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden)
{
    SafeDirectoryLister::open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (dir)
        closedir(dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir) {
        closedir(dir);
        dir = nullptr;
    }
    dir = opendir(path.c_str());
    if (dir == nullptr)
        throw IDirectoryLister::OpenFailureException();
    _ignoreHidden = !hidden;
    return true;
}

std::string SafeDirectoryLister::get()
{
    if (dir == nullptr) {
        return "";
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (!_ignoreHidden || entry->d_name[0] != '.') {
            return std::string(entry->d_name);
        }
    }
    throw IDirectoryLister::NoMoreFileException();
}
