#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <random>
#include <ctime>
#include <desktop_icon.h>

class Weapon
{
public:
    Weapon(std::string n, int hits, int distance, int max, int min, double acc): name(n), hitNumber(hits),
        range(distance), maxDamage(max), minDamage(min), accuracy(acc), holder(nullptr) {
        srand(time(0));
    }
    std::string getName() const;
    int getHitNumber() const;
    int getRange() const;
    int getDamage() const;
    double getAccuracy() const;
    int getX() const;
    int getY() const;
    void setHolder(Desktop_Icon* icon);
    virtual ~Weapon();
    //Might want to implement ammo later

private:
    std::string name;
    int hitNumber;
    int range;
    int maxDamage;
    int minDamage;
    double accuracy;
    Desktop_Icon* holder;
};

#endif // WEAPON_H
