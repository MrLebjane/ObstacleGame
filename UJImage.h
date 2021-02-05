#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <iostream>
#include <sstream>
using namespace std;

const char ARY_SYMBOLS[]={'.','P','R','$'};

enum Entities
{
    SPACE,
    PLAYER,
    ROCK,
    GOAL
};

// This class produces a black and white image instead of an RGB image.
class Image
{
public:
    static const int DEFAULT_ROWS = 20;
    static const int DEFAULT_COLS = 20;

    Image();
    Image(int intRows, int intCols);
    ~Image();

    int intGR;
    int intGC;
    int intPR;
    int intPC;

    //void CreateWorld();
    //void print();

    int getRows() const;
    int getCols() const;
    int getGameWorld(int intRow, int intCol) const;

    bool isInWorld(int intRow,int intCol);
    void setGameWorld(int intRow, int intCol,Entities Entity);
    Entities** AryWorld; // 2D array of black or white pixels.

private:
   int rows;
   int cols;

};




#endif // IMAGE_H_INCLUDED
