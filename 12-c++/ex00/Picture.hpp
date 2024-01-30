/*
** EPITECH PROJECT, 2024
** Picture.hpp
** File description:
** Paradigm Seminar, ex00
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
public:
    Picture() : _data("") {};
    Picture(const std::string &file) { getPictureFromFile(file); };
    ~Picture() = default;

    std::string getData() const { return _data; };
    bool getPictureFromFile(const std::string &file);

private:
    std::string _data;
};

#endif //PICTURE_HPP_