/*
** EPITECH PROJECT, 2024
** DroidMemory.hpp
** File description:
** Paradigm Seminar, ex01
*/

#include <iostream>

class DroidMemory {
public:
    DroidMemory();
    ~DroidMemory();
    void setFingerprint(size_t fingerprint) { _fingerprint = fingerprint;}
    void setExp(size_t exp) { _exp = exp;}
    size_t getFingerprint() const { return _fingerprint; }
    size_t getExp() const { return _exp; }
    DroidMemory &operator<<(DroidMemory &);
    DroidMemory &operator>>(DroidMemory &);
    DroidMemory &operator+=(DroidMemory const &);
    DroidMemory &operator+=(size_t);
    DroidMemory &operator+(size_t &);

private:
    size_t _fingerprint = random();
    size_t _exp = 0;
};

std::ostream &operator<<(std::ostream &, DroidMemory const &);
