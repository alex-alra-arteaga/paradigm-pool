/*
** EPITECH PROJECT, 2024
** Parts.hpp
** File description:
** Paradigm Seminar, ex01
*/

#include <string>

class Arms {
public:
    Arms(std::string serial = "A-01", bool functional = true);
    bool isFunctional() const { return _functional; }
    std::string serial() { return _serial; }
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};

class Legs {
public:
    Legs(std::string serial = "L-01", bool functional = true);
    bool isFunctional() const { return _functional; }
    std::string serial() { return _serial; }
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};

class Head {
public:
    Head(std::string serial = "H-01", bool functional = true);
    bool isFunctional() const { return _functional; }
    std::string serial() { return _serial; }
    void informations() const;

private:
    std::string _serial;
    bool _functional;
};