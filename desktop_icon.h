#ifndef DESKTOP_ICON_H
#define DESKTOP_ICON_H

#include <iostream>
#include <string>
#include "weapon.h"

class Desktop_Icon
{
public:
    Desktop_Icon(std::string n, int hp, double dodge, int speed, int x, int y, bool b) : name(n), currentHealth(hp),
        maxHealth(hp), dodgeChance(dodge), moveSpeed(speed), xLoc(x), yLoc(y), virus(nullptr), owned(b) {
        srand(time(0));
    }
    bool gotDamaged(Weapon* w);
    void equip(Weapon* w);
    virtual ~Desktop_Icon() = default;
    int getX() const;
    int getY() const;
    std::string getName() const;
    Weapon* getWeapon() const;
private:
    std::string name;
    int currentHealth;
    int maxHealth;
    double dodgeChance;
    int moveSpeed;
    int xLoc;
    int yLoc;
    Weapon* virus;
    bool owned;
};

#endif // DESKTOP_ICON_H
