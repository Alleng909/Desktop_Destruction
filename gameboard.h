#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include "weapon.h"
#include "desktop_icon.h"
#include <iostream>

class GameBoard
{
public:
    GameBoard(): width(0), height(0){}
    void setWidth(int x);
    void setHeight(int y);
    virtual ~GameBoard();
    void addWep(Weapon* w);
    void addIcon(Desktop_Icon* i);
    void equipAll();

    std::vector<Desktop_Icon*> returnIcons();
    size_t getWidth();
    size_t getHeight();
private:
    size_t width;
    size_t height;
    std::vector<Weapon*> weaponList;
    std::vector<Desktop_Icon*> iconList;
};

#endif // GAMEBOARD_H
