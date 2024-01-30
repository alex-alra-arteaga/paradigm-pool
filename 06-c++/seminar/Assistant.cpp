/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex04
*/

#include "Assistant.hpp"
#include <iostream>
#include <fstream>

Assistant::Assistant(int _id) {
    this->id = _id;
    std::cout << "Assistant " << this->id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant() {
    std::cout << "Assistant " << this->id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *_student, std::string _drinkName) {
    std::cout << "Assistant " << this->id << ": drink this, " << _student->getName() << " *sip coffee*" << std::endl;
    _student->drink(_drinkName);
}

std::string Assistant::readDrink(std::string _studentName) {
    std::string drinkName;
    std::string fileName = _studentName + ".drink";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Assistant " << this->id << ": " << _studentName << " didn't give me a drink *sip coffee*" << std::endl;
        return "";
    }
    std::getline(file, drinkName);
    file.close();
    if (std::remove(fileName.c_str()) != 0) {
        std::cout << "Assistant " << this->id << ": " << _studentName << " needs a " << drinkName << " *sip coffee*" << std::endl;
        return drinkName;
    }
    return "";
}

void Assistant::helpStudent(Student *student) {
    std::string drinkName = readDrink(student->getName());
    std::string studentName = student->getName();
    if (drinkName != "")
        giveDrink(student, drinkName);
    else
        std::cout << "Assistant " << this->id << ": " << studentName << " seems fine *sip coffee*" << std::endl;
}

void Assistant::timeCheck(void) {
    bool isWorking = this->getIsWorking();
    if (isWorking)
        std::cout << "Assistant " << this->id << ": Time to teach some serious business *sip coffee*" << std::endl;
    else
        std::cout << "Assistant " << this->id << ": Enough teaching for today *sip coffee*" << std::endl;
    this->setIsWorking(!isWorking);
}
