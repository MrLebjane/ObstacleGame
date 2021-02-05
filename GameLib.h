#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include "Image.h"
#include "PlayeLib.h"

#include <iostream>

using namespace std;


class Game:public Player
{
public:
    Game();
    Game(int intRows, int intCols);
    Game(const Game& objOriginal); /// Copy constructor.
    ~Game();

    void CreateWorld();
    void Move(char Action);
    void print();
    virtual bool isInWorld(int intRow,int intCol);


private:
    Image* TwoDGame;
};





#endif // GAMELIB_H_INCLUDED
