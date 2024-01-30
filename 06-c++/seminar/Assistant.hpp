/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex04
*/

#include "Student.hpp"
#include <string>

class Assistant {
public:
    Assistant(int _id);
    ~Assistant();

    void giveDrink(Student *_student, std::string _drinkName);
    std::string readDrink(std::string _studentName);
    void helpStudent(Student *student);
    void timeCheck(void);

    void setIsWorking(bool _isWorking) {
        this->isWorking = _isWorking;
    }

    bool getIsWorking() {
        return this->isWorking;
    }

private:
    int id;
    bool isWorking = false;
};