#include "gameboard.h"

void GameBoard::setWidth(int x) {
    width = x;
}

void GameBoard::setHeight(int y) {
    height = y;
}

void GameBoard::addWep(Weapon* w) {
    weaponList.push_back(w);
}

void GameBoard::addIcon(Desktop_Icon* i) {
    iconList.push_back(i);
}

void GameBoard::equipAll() {
    std::cout << "Equipping weapons";
    for(size_t i = 0; i < weaponList.size(); i++)
        iconList[i]->equip(weaponList[i]);
}

GameBoard::~GameBoard() {
    for(auto weapon: weaponList) {
        delete weapon;
    }
    for(auto icon: iconList) {
        delete icon;
    }
    //Delete other stuff when implemented.
}
