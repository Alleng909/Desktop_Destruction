#ifndef GAMELOADER_H
#define GAMELOADER_H
#include <fstream>
#include <string>
#include "gameboard.h"
class GameLoader
{
public:
    GameLoader(std::string fileName, GameBoard* game) : file(fileName), board(game){}
    void load();
    virtual ~GameLoader();
private:
    std::string file;
    GameBoard* board;
};

#endif // GAMELOADER_H
