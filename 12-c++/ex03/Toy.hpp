/*
** EPITECH PROJECT, 2024
** Toy.hpp
** File description:
** Paradigm Seminar, ex03
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy() : _name("toy"), _type(BASIC_TOY), _picture() {};
    Toy(const ToyType type, const std::string &name, const std::string &file) : _name(name), _type(type), _picture(file) {};
    Toy(const Toy &other);
    Toy(Toy &&other);

    ~Toy() = default;

    Toy &operator=(const Toy &other);

    ToyType getType() const { return _type; };
    std::string getName() const { return _name; };
    std::string getAscii() const { return _picture.getData(); };
    void setName(const std::string &name) { _name = name; };
    bool setAscii(const std::string &file) { return _picture.getPictureFromFile(file); };

    virtual void speak(const std::string statement);

private:
    std::string _name;
    ToyType _type;
    Picture _picture;
};

#endif //TOY_HPP_