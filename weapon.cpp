#include "weapon.h"
#include <iostream>

//Returns name of weapon
std::string Weapon::getName() const {
    return name;
}

//Returns the number of times it fires per action.
int Weapon::getHitNumber() const {
    return hitNumber;
}

//NOTE MIGHT WANT A MIN RANGE TOO, (for snipers)
//Returns range of weapon
int Weapon::getRange() const {
    return range;
}

//Returns a randomized damage value.
int Weapon::getDamage() const {
    return rand() % (maxDamage - minDamage) + minDamage;
}

double Weapon::getAccuracy() const {
    return accuracy;
}

int Weapon::getX() const {
    return holder->getX();
}

int Weapon::getY() const {
    return holder->getY();
}

void Weapon::setHolder(Desktop_Icon* icon) {
    holder = icon;
}

Weapon::~Weapon() {
    std::cout << "DELETING " << name << " " << hitNumber << " " << range << " " << maxDamage
         << " " << minDamage << " " << accuracy;
}
//NOTE TO SELF TO GET TEMPLATE FOR CHECKING RANGE?
