#include "PlayeLib.h"
#include "Image.h"
#include "LibCommon.h"

Player::Player()
{
    // Allocate memory for the objects.
    TwoDPlayer = new Image;
}

Player::Player(int intRows, int intCols)
{
    // Use their respective parameterised constructors.
    TwoDPlayer = new Image(intRows, intCols);
}

Player::Player(const Player& objOriginal)
{
    // Allocate new memory from the freestore.
    TwoDPlayer = new Image;

    // Perform deep copies of the pixel arrays.
   for(int r = 0; r < objOriginal.TwoDPlayer->getRows(); r++)
    {
        for(int c = 0; c < objOriginal.TwoDPlayer->getCols(); c++)
        {
            TwoDPlayer->setGameWorld(r, c, SPACE);

        }
    }

}

void Player::Move(char Action)
{
    int intTR=TwoDPlayer->intPR;
    int intTC=TwoDPlayer->intPC;

    switch(Action)
    {
    case 'w':
         intTR--;
        break;

    case 's':
         intTR++;
        break;

    case 'a':
         intTC--;
        break;

    case 'd':
         intTC++;
        break;
    }
    if(isInWorld(intTR,intTC))
    {
        if(TwoDPlayer->AryWorld[intTR][intTC]==SPACE)
        {
            TwoDPlayer->intPR=intTR;
            TwoDPlayer->intPC=intTC;
        }
        else if(TwoDPlayer->AryWorld[intTR][intTC]==GOAL)
        {
            cout<<"YOU WIN"<<endl;
            system("pause");
            exit(SUCCESS);
        }
        else if(TwoDPlayer->AryWorld[intTR][intTC]==ROCK)
        {
            cout<<"YOU LOSE"<<endl;
            system("pause");
            exit(SUCCESS);
        }
    }

}

bool Player::isInWorld(int intTR,int intTC)
{
    TwoDPlayer->isInWorld(intTR,intTC);
}
