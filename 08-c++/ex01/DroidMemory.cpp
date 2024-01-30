/*
** EPITECH PROJECT, 2024
** Memory.cpp
** File description:
** Paradigm Seminar, ex01
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() {}

DroidMemory::~DroidMemory() {}

DroidMemory &DroidMemory::operator<<(DroidMemory &other)
{
    this->_exp += other._exp;
    this->_fingerprint = this->_fingerprint ^ other._fingerprint;
    return *this;
}

std::ostream &operator<<(std::ostream &os, DroidMemory const &k)
{
    os << "DroidMemory '" << k.getFingerprint() << "', " << k.getExp();
    return os;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other)
{
    other._exp += this->_exp;
    this->_fingerprint = other._fingerprint ^ this->_fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &other)
{
    this->_exp += this->_exp;
    this->_fingerprint = this->_fingerprint ^ this->_fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->_exp = this->_exp + exp;
    this->_fingerprint = this->_fingerprint ^ exp;
    return *this;
}

DroidMemory &DroidMemory::operator+(size_t &exp)
{
    DroidMemory *result = new DroidMemory();

    result->_exp = this->_exp + exp;
    result->_fingerprint = this->_fingerprint ^ exp;
    return *result;
}
