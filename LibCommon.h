#ifndef LIBCOMMON_H_INCLUDED
#define LIBCOMMON_H_INCLUDED

#include <iostream>
#include <cassert>

enum StatusCode
{
    ERROR_RANGE = -1,
    SUCCESS
};


void enforceRange(int intValue, int intMin, int intMax);
int rangedRandom(int intLB, int intUB);
bool isInWorld(int intRow,int intCol);

#endif // LIBCOMMON_H_INCLUDED
