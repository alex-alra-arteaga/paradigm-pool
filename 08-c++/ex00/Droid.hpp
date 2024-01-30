/*
** EPITECH PROJECT, 2024
** Droid.hpp
** File description:
** Paradigm Seminar, ex00
*/

#include <string>

class Droid {
public:
    Droid(std::string serial = "");
    Droid(const Droid &otherDroid);
    ~Droid();
    Droid &operator=(const Droid &otherDroid);
    bool operator==(const Droid &otherDroid) const;
    bool operator!=(const Droid &otherDroid) const;
    Droid &operator<<(size_t &energy);

    std::string getId() const { return this->Id; }
    size_t getEnergy() const { return this->Energy; }
    size_t getAttack() const { return this->Attack; }
    size_t getToughness() const { return this->Toughness; }
    std::string *getStatus() const { return this->Status; }

    void setId(std::string id) { this->Id = id; }
    void setEnergy(size_t energy) { this->Energy = energy; }
    void setStatus(std::string *status) { this->Status = status; }

private:
    std::string Id;
    size_t Energy;
    const size_t Attack;
    const size_t Toughness;
    std::string *Status;
};

std::ostream &operator<<(std::ostream &s, const Droid &d);