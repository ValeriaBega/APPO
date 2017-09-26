
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cassert> // used by boundCheck

#include "constants.h"

//throws a runtime error if avalue isn't between boundStart and boundEnd, boundEnd NOT included
void boundCheck(int boundStart, int boundEnd, int avalue);
//converts an index e.g. 6 to two values used in a 2D array, 6 is (2,0)
void convert1Dto2D(int index, int &row, int &column);
//this converts (2,0) to 6
void convert2Dto1D(int row, int column, int &index);
//read a string and return an int
int getInt();

#endif




