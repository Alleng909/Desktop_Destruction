#include "mainwindow.h"
#include <QApplication>
#include "weapon.h";
#include "desktop_icon.h";

int main(int argc, char *argv[]) //NOTE NEED TO EQUIP A NEW WEAPON TO EACH SHIP
{
    srand(time(0));
    Weapon* Trojan = new Weapon("Trojan", 2, 4, 10, 4, .9);
    Desktop_Icon* Dumb = new Desktop_Icon("Dumb", 100, .1, 3, 1, 1);
    Dumb->equip(Trojan);
    std::cout << "Start" << (double)rand()/RAND_MAX << " " << (double)rand()/RAND_MAX << "\n";
    Dumb->gotDamaged(Trojan);
    Dumb->gotDamaged(Trojan);
    std::cout << "TEST\n";
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
    return 0;
}
