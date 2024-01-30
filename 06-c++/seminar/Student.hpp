/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex03
*/

#include <string>

class Student {
public:
    Student(std::string _name);
    ~Student();

    bool learn(std::string _text);
    void drink(std::string _drinkName);

    std::string getName() {
        return this->name;
    }

private:
    std::string name;
    unsigned int energyPoints = 100;
};
