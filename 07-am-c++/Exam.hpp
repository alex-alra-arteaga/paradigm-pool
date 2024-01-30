/*
** EPITECH PROJECT, 2024
** Exam.hpp
** File description:
** Paradigm Seminar, ex00
*/

// constructor arg -> boolean

class Exam {
public:
    Exam(bool *cheatFlag);
    // ~Exam();
    void (Exam::*kobayashiMaru)(int);
    void start(int);
    bool isCheating() { return cheat; }
    bool* cheatPtr;
    static bool cheat;
};
