/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex05
*/

#include "Dean.hpp"
#include <iostream>
#include <fstream>

#define FAILED false

Dean::Dean(std::string _name) {
    std::cout << "Dean " << _name << ": I'm Dean " << _name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean() {
    std::cout << "Dean " << this->name << ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string subject) {
    std::string drinksNames[5] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    std::string studentName = student->getName();
    if (student->learn(subject) == FAILED) {
        std::cout << "Dean " << this->name << ": All work and no play makes " << studentName << " a dull student." << std::endl;
        std::ofstream file(studentName + ".drink");
        file << drinksNames[std::rand() % 5] << ".drink" << std::endl;
        file.close();
    }
}

void Dean::timeCheck(void) {
    bool isWorking = this->getIsWorking();
    if (isWorking)
        std::cout << "Dean " << this->name << ": Where is is everyone?" << std::endl;
    else
        std::cout << "Dean " << this->name << ": Don't forget to close the windows when you leave." << std::endl;
    this->setIsWorking(!isWorking);
}