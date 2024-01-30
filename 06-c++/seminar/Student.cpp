/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex03
*/

#include "Student.hpp"
#include <string>
#include <iostream>
#include <regex>
#include <algorithm>

#define MAX_ENERGY_POINTS (unsigned int)100

Student::Student(std::string _name) {
    std::cout << "Student " << _name << ": I'm ready to learn C++." << std::endl;
    this->name = _name;
}

Student::~Student() {
    std::cout << "Student " << this->name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(std::string _text) {
    if (energyPoints >= 42) {
        energyPoints -= 42;
        std::cout << "Student " << this->name << ": " << _text << std::endl;
        return true;
    }
    std::cout << std::regex_replace(_text, std::regex("C\\+\\+"), "shit") << std::endl;
    return false;
}

void Student::drink(std::string _drinkName) {
    if (_drinkName == "Red Bull") {
        std::cout << "Student " << this->name << ": Red Bull gives you wings!" << std::endl;
        this->energyPoints = std::min(this->energyPoints + 32, MAX_ENERGY_POINTS);
    } else if (_drinkName == "Monster") {
        std::cout << "Student " << this->name << ": Unleash the beast!" << std::endl;
        this->energyPoints = std::min(this->energyPoints + 64, MAX_ENERGY_POINTS);
    } else {
        std::cout << "Student " << this->name << ": ah, yes... enslaved moisture." << std::endl;
        this->energyPoints = std::min(this->energyPoints + 1, MAX_ENERGY_POINTS);
    }
}
