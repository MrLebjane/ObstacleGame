#include "GameLib.h"
#include "LibCommon.h"
#include "Image.h"
#include <cassert>

Game::Game()
{
    // Allocate memory for the objects.
    TwoDGame = new Image;
}

Game::Game(int intRows, int intCols)
{
    // Use their respective parameterised constructors.
    TwoDGame = new Image(intRows, intCols);
}

Game::Game(const Game& objOriginal)
{
    // Allocate new memory from the freestore.
    TwoDGame = new Image;

    // Perform deep copies of the pixel arrays.
   for(int r = 0; r < objOriginal.TwoDGame->getRows(); r++)
    {
        for(int c = 0; c < objOriginal.TwoDGame->getCols(); c++)
        {
            TwoDGame->setGameWorld(r, c, SPACE);

        }
    }

}

void Game::CreateWorld()
{
    for(int r = 0; r < TwoDGame->getRows(); r++)
    {
        for(int c = 0; c < TwoDGame->getCols(); c++)
        {
            TwoDGame->setGameWorld(r, c, SPACE);
            int intRoll=rangedRandom(1,100);
            if(intRoll<=10)
            {
                TwoDGame->AryWorld[r][c]=ROCK;
            }
            /*else
            {
                TwoDGame->AryWorld[r][c]=SPACE;
            }*/
        }
    }
    TwoDGame->intGR=rangedRandom(0,TwoDGame->getRows()-1);
    TwoDGame->intGC=rangedRandom(0,TwoDGame->getCols()-1);
    TwoDGame->setGameWorld(TwoDGame->intGR,TwoDGame->intGC, GOAL);

    TwoDGame->intPR=rangedRandom(0,TwoDGame->getRows()-1);
    TwoDGame->intPC=rangedRandom(0,TwoDGame->getCols()-1);
    while((TwoDGame->intGR==TwoDGame->intPR && TwoDGame->intGC==TwoDGame->intPC)||TwoDGame->AryWorld[TwoDGame->intPR][TwoDGame->intPC]==ROCK)
    {
       TwoDGame->intPR=rangedRandom(0,TwoDGame->getRows()-1);
       TwoDGame->intPC=rangedRandom(0,TwoDGame->getCols()-1);
    }


}

void Game::print()
{

    for(int r = 0; r <TwoDGame->getRows(); r++)
    {
        for(int c = 0; c <TwoDGame->getCols(); c++)
        {
            if(r==TwoDGame->intPR && c==TwoDGame->intPC)
            {
                cout<<ARY_SYMBOLS[PLAYER];
            }
            else if(r==TwoDGame->intGR && c==TwoDGame->intGC)
            {
                cout<<ARY_SYMBOLS[GOAL];
            }
            else if(TwoDGame->AryWorld[r][c]==ROCK)
            {
                cout<<ARY_SYMBOLS[ROCK];
            }
            else //if(TwoDGame->AryWorld[c][r]==SPACE)
            {
                cout<<ARY_SYMBOLS[SPACE];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

void Game::Move(char Action)
{
    int intTR=TwoDGame->intPR;
    int intTC=TwoDGame->intPC;
    //cout<<TwoDGame->intPC;
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
        if(TwoDGame->AryWorld[intTR][intTC]==SPACE)
        {
            TwoDGame->intPR=intTR;
            TwoDGame->intPC=intTC;
        }
        else if(TwoDGame->AryWorld[intTR][intTC]==GOAL)
        {
            cout<<"YOU WIN"<<endl;
            system("pause");
            exit(SUCCESS);
        }
        else if(TwoDGame->AryWorld[intTR][intTC]==ROCK)
        {
            cout<<"YOU LOSE"<<endl;
            system("pause");
            exit(SUCCESS);
        }
    }

}

bool Game::isInWorld(int intTR,int intTC)
{
    TwoDGame->isInWorld(intTR,intTC);
}

Game::~Game()
{
     //Deallocate memory.
    delete TwoDGame;

}
