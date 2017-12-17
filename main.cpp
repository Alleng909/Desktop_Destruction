#include "mainwindow.h"
#include <QApplication>
#include "weapon.h";
#include "desktop_icon.h";
#include "gameboard.h"
#include "gameloader.h"
#include <iostream>

int main(int argc, char *argv[]) //NOTE NEED TO EQUIP A NEW WEAPON TO EACH SHIP
{
    srand(time(0));
    std::string f = "Load1.txt";
    GameBoard* boardPointer = new GameBoard();
    GameLoader loader(f, boardPointer);
    std::cout << "Initializing load\n";
    loader.load();
    std::cout << "Terminating load\n";

    QApplication a(argc, argv);
    MainWindow w(boardPointer);
    w.showMaximized();
    w.setFixedSize(1000,800);
    w.show();

    return a.exec();

    return 0;
}
