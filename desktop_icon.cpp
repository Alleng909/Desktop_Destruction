#include "desktop_icon.h"

//Calculates if icon is hit, and returns true if icon is destroyed.
bool Desktop_Icon::gotDamaged(Weapon* w) {
    double hitChance = w->getAccuracy()*(1-dodgeChance); //Calculates percent chance to hit off arbitrary algorithm.
    std::cout << "This was called\n"; //Tester
    std::cout << w->getHitNumber() << " & " << hitChance << "\n"; //Tester
    for(int i = 0; i < w->getHitNumber(); i++) {
        if (hitChance > (double)rand()/RAND_MAX) {
            int damage = w->getDamage();
            std::cout << "Shot " << i+1 << " hit for " << damage << " damage.\n";
            currentHealth -= damage;
            if (currentHealth <= 0) {
                std::cout << name << " was destroyed by " << w->getName() << ".\n";
                return true;
            }
        } else {
            std::cout << "Shot " << i+1 << " failed to connect.\n";
        }
    }
    return false;
}

void Desktop_Icon::equip(Weapon *w) {
    virus = w;
}

int Desktop_Icon::getX() const {
    return xLoc;
}
int Desktop_Icon::getY() const {
    return yLoc;
}

std::string Desktop_Icon::getName() const {
    return name;
}
