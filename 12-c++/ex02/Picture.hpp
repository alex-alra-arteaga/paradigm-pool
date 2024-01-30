/*
** EPITECH PROJECT, 2024
** Picture.hpp
** File description:
** Paradigm Seminar, ex02
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
public:
    Picture() : _data("") {};
    Picture(const std::string &file) { getPictureFromFile(file); };
    Picture(const Picture &other);
    Picture(Picture &&other);

    ~Picture() = default;

    Picture &operator=(const Picture &other);

    std::string getData() const { return _data; };
    bool getPictureFromFile(const std::string &file);



private:
    std::string _data;
};

#endif //PICTURE_HPP_