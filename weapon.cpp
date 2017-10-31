#include "weapon.h"

//Returns name of weapon
std::string Weapon::getName() const {
    return name;
}

//Returns the number of times it fires per action.
int Weapon::getHitNumber() const {
    return hitNumber;
}

//NOTE MIGHT WANT A MIN RANGE TOO, aka sniper
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

//NOTE TO SELF TO GET TEMPLATE FOR CHECKING RANGE?
