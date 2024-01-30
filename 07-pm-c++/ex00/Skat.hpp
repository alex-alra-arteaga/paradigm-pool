/*
** EPITECH PROJECT, 2024
** Skat.hpp
** File description:
** Paradigm Seminar, ex00
*/

#include <string>

class Skat
{
public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();
    int stimPaks() { return _stimPaks; }
    const std::string &name() const { return _name; };
    void shareStimPaks(int number, int stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    // make this callable if the class is immutable
    void status() const;

    static int stock;
private:
    std::string _name;
    int _stimPaks;
};