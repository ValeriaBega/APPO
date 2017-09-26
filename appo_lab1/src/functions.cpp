#include "functions.h"

void boundCheck(int boundStart, int boundEnd, int avalue)
{
	assert(avalue >= boundStart && avalue < boundEnd);
}

void convert1Dto2D(int index, int &row, int &column)
{
	row = int(index / ROWS);
	column = index - row * ROWS;
}

void convert2Dto1D(int row, int column, int &index)
{
	index = (row * ROWS) + column;
}

int getInt()
{
	std::string temp;
	std::getline(std::cin, temp);
	std::stringstream ss(temp);
	int i;
	ss >> i;
	return i;
}


