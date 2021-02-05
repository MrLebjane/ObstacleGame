#include "Image.h"
#include "LibCommon.h"

#include<cassert>
#include <sstream>

using namespace std;

Image::Image() : Image(DEFAULT_ROWS, DEFAULT_COLS) {}

Image::Image(int intRows, int intCols)
{
    rows = intRows;
    cols = intCols;

    AryWorld = new Entities*[rows];
    for(int r = 0; r < rows; r++)
    {
        AryWorld[r] = new Entities[cols];
        for(int c = 0; c < cols; c++)
        {
            AryWorld[r][c] = SPACE;
        }
    }
}

bool Image::isInWorld(int intRow,int intCol)
{
    if(intRow<0)return false;
    if(intRow>=rows)return false;
    if(intCol<0)return false;
    if(intCol>=cols)return false;

    return true;
}

Image::~Image()
{
    for(int r = 0; r < rows; r++)
    {
        delete [] AryWorld[r];
    }
    delete AryWorld;
}


int Image::getRows() const
{
    return rows;
}

int Image::getCols() const
{
    return cols;
}

int Image::getGameWorld(int intRow, int intCol) const
{
    enforceRange(intRow, 0, rows - 1);
    enforceRange(intCol, 0, cols - 1);
    return AryWorld[intRow][intCol];
}

void Image::setGameWorld(int intRow, int intCol,Entities Entity)
{
    enforceRange(intRow, 0, rows - 1);
    enforceRange(intCol, 0, cols - 1);
    AryWorld[intRow][intCol] = Entity;
}




