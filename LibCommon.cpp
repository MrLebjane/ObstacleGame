#include "LibCommon.h"
#include "Image.h"

void enforceRange(int intValue, int intMin, int intMax)
{
    if(intValue < intMin)
    {
        std::cerr << "Error: " << intValue << " < " << intMin;
        exit(ERROR_RANGE);
    }

    if(intValue > intMax)
    {
        std::cerr << "Error: " << intValue << " > " << intMax;
        exit(ERROR_RANGE);
    }
}

int rangedRandom(int intLB, int intUB)
{
    assert(intLB < intUB);
    int intRange = intUB - intLB + 1;
    return rand() % intRange + intLB;
}

/*bool isInWorld(int intRow,int intCol)
{
    if(intRow<0)return false;
    if(intRow>=Image->DEFAULT_ROWS)return false;
    if(intCol<0)return false;
    if(intCol>=Image->DEFAULT_COLS)return false;

    return true;
}*/
