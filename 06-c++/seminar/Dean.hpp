/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex05
*/

#include "Assistant.hpp"
#include <iostream>
#include <fstream>

class Dean {
public:
    Dean(std::string _name);
    ~Dean();

    void teachStudent(Student *student, std::string subject);
    void timeCheck(void);
    void setIsWorking(bool _isWorking) {
        this->isWorking = _isWorking;
    }
    bool getIsWorking(void) {
        return this->isWorking;
    }

private:
    std::string name;
    bool isWorking = true;
};
