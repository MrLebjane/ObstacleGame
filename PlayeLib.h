#ifndef PLAYELIB_H_INCLUDED
#define PLAYELIB_H_INCLUDED


#include "Image.h"

#include <iostream>

using namespace std;

class Player
{
public:
    Player();
    Player(int intRows, int intCols);
    Player(const Player& objOriginal); /// Copy constructor.
    virtual void Move(char Action);
    virtual bool isInWorld(int intRow,int intCol);



protected:
    Image* TwoDPlayer;

};



#endif // PLAYELIB_H_INCLUDED
