#include "gameloader.h"
#include <fstream>
#include <string>
#include <iostream>
void GameLoader::load() {
    try {
        std::ifstream reader(file);
        int x;
        std::string s;
        reader >> x;
        board->setWidth(x);
        reader >> x;
        board ->setHeight(x);
        reader >> x; //Getting number of wep/icons
        getline(reader,s); //Getting detail line out of the way
        getline(reader,s);
        std::cout << s;
        //Getting weapon info
        for(int i = 0; i < x; i++) { //Weapon Name	Hits	Range	Max	Min	Accuracy
            std::string name;
            int hits, range, max, min;
            double acc;
            reader >> name;
            reader >> hits;
            reader >> range;
            reader >> max;
            reader >> min;
            reader >> acc;
            Weapon* w = new Weapon(name,hits,range,max,min,acc);
            board->addWep(w);
        }

        getline(reader, s); //Reading out info line
        getline(reader,s);
        getline(reader,s);
        std::cout << s;

        //Getting Icon info
        for(int i = 0; i < x; i++) { //Icon Name	Hp	Dodge	Speed	xLoc	yLoc	Ownership
            std::string name;
            int hp, speed, xLoc, yLoc;
            double dodge;
            bool own;
            reader >> name;
            reader >> hp;
            reader >> dodge;
            reader >> speed;
            reader >> xLoc;
            reader >> yLoc;
            reader >> own;

            std::cout << " " << name;
            std::cout << " " << hp;
            std::cout << " " << dodge;
            std::cout << " " << speed;
            std::cout << " " << xLoc;
            std::cout << " " << yLoc;
            std::cout << " " << own;
            Desktop_Icon* icon= new Desktop_Icon(name,hp,dodge,speed,xLoc,yLoc,own);
            board->addIcon(icon);
        }
        std::cout << "Equipping weapons\n";
        board->equipAll();

        reader.close();
    } catch(std::exception e) {
        std::cout << "Error in loading file";
        throw;
    }
}
