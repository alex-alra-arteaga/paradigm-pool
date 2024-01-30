/*
** EPITECH PROJECT, 2024
** Phaser.cpp
** File description:
** Paradigm Seminar, ex03
*/

#include "Phaser.hpp"
#include "Sounds.hpp"
#include <iostream>

Sounds::Sounds() {}

Phaser::Phaser(int maxAmmo, AmmoType type)
{
    sounds = new Sounds();
    _maxAmmo = maxAmmo;
    _type = type;
    _magazine.assign(maxAmmo, type);
}

Phaser::~Phaser() {}

void Phaser::fire()
{
    if (_magazine.empty()) {
        std::cout << "Clip empty, please reload" << std::endl;
    } else {
        std::cout << getSoundForType(_magazine.front()) << std::endl;
        _magazine.erase(_magazine.begin());
    }
}

void Phaser::ejectClip()
{
    _magazine.clear();
}

void Phaser::changeType(AmmoType newType)
{
    std::fill(_magazine.begin(), _magazine.end(), newType);
    std::cout << "Switching ammo to type: " << ammoTypeToString(newType) << std::endl;
}

void Phaser::reload()
{
    int missingAmmo = _maxAmmo - _magazine.size();
    for (int i = 0; i < missingAmmo; i++)
        _magazine.push_back(_type);
    std::cout << "Reloading..." << std::endl;
}

void Phaser::addAmmo(AmmoType type)
{
    if (_magazine.size() == static_cast<size_t>(_maxAmmo)) {
        std::cout << "Clip full" << std::endl;
    } else {
        _magazine.push_back(type);
    }
}

int Phaser::getCurrentAmmos() const
{
    return _magazine.size();
}

std::string Phaser::getSoundForType(AmmoType type) const
{
    switch (type) {
        case REGULAR: return this->sounds->Regular;
        case PLASMA:  return this->sounds->Plasma;
        case ROCKET:  return this->sounds->Rocket;
        default:      return "";
    }
}

std::string Phaser::ammoTypeToString(AmmoType type) const
{
    switch (type) {
        case REGULAR: return "regular";
        case PLASMA:  return "plasma";
        case ROCKET:  return "rocket";
        default:      return "unknown";
    }
}
