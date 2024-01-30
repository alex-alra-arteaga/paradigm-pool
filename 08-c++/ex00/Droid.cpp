/*
** EPITECH PROJECT, 2024
** Droid.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include "Droid.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Droid &d);

Droid::Droid(std::string serial) : Attack(25), Toughness(15)
{
    this->setId(serial);
    this->setEnergy(50);
    this->setStatus(new std::string("Standing by"));
    std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &otherDroid) : Attack(otherDroid.Attack), Toughness(otherDroid.Toughness)
{
    this->Id = otherDroid.getId();
    this->Energy = otherDroid.getEnergy();
    this->Status = new std::string(*otherDroid.getStatus());
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
}

Droid &Droid::operator=(const Droid &otherDroid)
{
    if (this == &otherDroid)
        return *this;
    this->Id = otherDroid.getId();
    this->Energy = otherDroid.getEnergy();
    delete this->Status;
    this->Status = new std::string(*otherDroid.getStatus());
    return *this;
}


bool Droid::operator==(const Droid &otherDroid) const
{
    return (this->Id == otherDroid.getId() && this->Energy == otherDroid.getEnergy() &&
            this->Attack == otherDroid.getAttack() && this->Toughness == otherDroid.getToughness()
            && *this->Status == *otherDroid.getStatus());
}

bool Droid::operator!=(const Droid &otherDroid) const
{
    return (this->Id != otherDroid.getId() || this->Energy != otherDroid.getEnergy() ||
            this->Attack != otherDroid.getAttack() || this->Toughness != otherDroid.getToughness()
            || *this->Status != *otherDroid.getStatus());
}

std::ostream &operator<<(std::ostream &out, const Droid &d)
{
    out << "Droid '" << d.getId() << "', " << *d.getStatus() << ", " << d.getEnergy();
    return out;
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->Energy + energy >= 100) {
        energy -= 100 - Energy;
        this->Energy = 100;
    } else {
        this->Energy += energy;
        energy = 0;
    }
    return *this;
}
