/*
** EPITECH PROJECT, 2024
** Picture.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Picture.hpp"
#include <fstream>
#include <string>

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
