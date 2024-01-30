/*
** EPITECH PROJECT, 2024
** Picture.cpp
** File description:
** Paradigm Seminar, ex05
*/

#include "Picture.hpp"
#include <fstream>
#include <string>

Picture::Picture(const Picture &other)
{
    _data = other._data;
}

Picture::Picture(Picture &&other)
{
    _data = other._data;
    other._data = "";
}

Picture &Picture::operator=(const Picture &other)
{
    _data = other._data;
    return *this;
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string line;
    std::ifstream picture(file, std::ifstream::in);

    if (!picture) {
        _data = "ERROR";
        return false;
    }
    while (std::getline(picture, line))
        _data += line + "\n";
    return true;
}
