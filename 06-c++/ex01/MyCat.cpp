/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, ex01
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::cout << line << std::endl;
        }
        std::cout << line << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::ifstream file(argv[i], std::ifstream::in);
        if (!file) {
            std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
            return 84;
        } else {
            std::string line;
            while (std::getline(file, line))
                std::cout << line << std::endl;
        }
    }
    return 0;
}
