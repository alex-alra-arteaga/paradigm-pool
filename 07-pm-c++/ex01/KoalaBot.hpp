/*
** EPITECH PROJECT, 2024
** KoalaBot.hpp
** File description:
** Paradigm Seminar, ex01
*/

#include <string>
class Arms;
class Legs;
class Head;

class KoalaBot {
public:
    KoalaBot(std::string serial = "Bob-01");
    // ~KoalaBot();
    void setParts(Arms &arms) { _arms = &arms; };
    void setParts(Legs &legs) { _legs = &legs; };
    void setParts(Head &head) { _head = &head; }
    void swapParts(Arms &arms);
    void swapParts(Legs &legs);
    void swapParts(Head &head);
    void informations() const;
    bool status() const;

private:
    std::string _serial;
    Arms *_arms;
    Legs *_legs;
    Head *_head;
};