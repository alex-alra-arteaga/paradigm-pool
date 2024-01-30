/*
** EPITECH PROJECT, 2024
** Phaser.hpp
** File description:
** Paradigm Seminar, ex03
*/

#include <string>
#include <vector>

class Sounds;

class Phaser {
public:
    enum AmmoType {
        REGULAR,
        PLASMA,
        ROCKET
    };
    Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
    ~Phaser();
    void fire();
    void ejectClip();
    void changeType(AmmoType newType);
    void reload();
    void addAmmo(AmmoType type);
    int getCurrentAmmos() const;
    std::string getSoundForType(AmmoType type) const;
    std::string ammoTypeToString(AmmoType type) const;

private:
    Sounds *sounds;
    static const int Empty = 0;
    int _maxAmmo;
    AmmoType _type;
    std::vector<AmmoType> _magazine;
};