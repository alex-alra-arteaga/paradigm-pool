/*
** EPITECH PROJECT, 2024
** DirectoryLister.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "DirectoryLister.hpp"
#include <dirent.h>

DirectoryLister::DirectoryLister() : _ignoreHidden(false) {}

DirectoryLister::~DirectoryLister() {
    if (dir)
        closedir(dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir) {
        closedir(dir);
        dir = nullptr;
    }
    dir = opendir(path.c_str());
    if (dir == nullptr) {
        std::perror(path.c_str());
        return false;
    }
    _ignoreHidden = !hidden;
    return true;
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
{
    DirectoryLister::open(path, hidden);
}

std::string DirectoryLister::get()
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
    return "";
}