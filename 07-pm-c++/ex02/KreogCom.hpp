/*
** EPITECH PROJECT, 2024
** KreogCom.hpp
** File description:
** Paradigm Seminar, ex02
*/

class KreogCom {
public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();
    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom() { return next; };
    void ping() const;
    void locateSquad() const;

private:
    const int m_serial;
    int x;
    int y;
    KreogCom *next;
};