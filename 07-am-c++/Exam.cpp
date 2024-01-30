/*
** EPITECH PROJECT, 2024
** Exam.cpp
** File description:
** Paradigm Seminar, ex00
*/

#include <iostream>
#include "Exam.hpp"

bool Exam::cheat = false;

Exam::Exam(bool *cheatFlag) {
    cheatPtr = cheatFlag;
}

void Exam::start(int vessels) {
    std::cout << "[The exam is starting]$" << std::endl;
    std::cout << vessels << " Klingon vessels appeared out of nowhere.$" << std::endl;
    std::cout << "they are fully armed and shielded$" << std::endl;
    if (*cheatPtr)
        std::cout << "What the... someone changed the parameters of the exam !$" << std::endl;
    else
        std::cout << "This exam is hard... you lost again.$" << std::endl;
}
