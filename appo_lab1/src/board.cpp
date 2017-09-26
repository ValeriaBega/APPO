#include "board.h"

Board::Board() {
    Clear();
}

void Board::Clear() {
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLUMNS; ++j) {
          	table[i][j] = EMPTY;
        }
    }
}

std::ostream &operator << (std::ostream &os, const Board &b) {
	for(int i = 0; i < ROWS; ++i) {
		for(int j = 0; j < COLUMNS; ++j) {
			std::cout << b.table[i][j];
			if(j != ROWS - 1)
				std::cout << " | ";
		}
		std::cout << "\n";
		if(i != ROWS - 1) {
			for(int k = 0; k < ROWS; ++k) {
				if(k != ROWS - 1)
					std::cout << "-----";
			}
		}
		std::cout << "\n";
	}
	return os;
}

void Board::setSlot(int row, int column, char ans) {
    boundCheck(0, ROWS, row);
	boundCheck(0, ROWS, column);
	table[row][column] = ans;
}

void Board::setSlot(int index, char ans) {
    boundCheck(0, ROWS * ROWS, index);
	int i, j;
	convert1Dto2D(index, i, j);
	table[i][j] = ans;
}

char Board::getSlot(int row, int column) const {
    boundCheck(0, ROWS, row);
	boundCheck(0, ROWS, column);
	return table[row][column];
}

char Board::getSlot(int index) const {
    boundCheck(0, ROWS * ROWS, index);
	int i, j;
	convert1Dto2D(index, i, j);
	return table[i][j];
}

int Board::numFreeSlots(char ans) {
    int cnt = 0;
    for(int i = 0; i < ROWS; ++i) {
       for(int j = 0; j < COLUMNS; ++j) {
        if(table[i][j] != ans)
				++cnt;
       }
    }
	return cnt;
}

bool Board::success(DIRECTION direction, char ans) {
    switch(direction) {
	case Board::HORIZONTAL:

		for(int i = 0; i < ROWS; ++i) {
			if(getSlot(i, 0) == getSlot(i, 1) && getSlot(i, 0) == getSlot(i, 2) )
				if(getSlot(i, 0) == ans)
					return true;
		}

	case Board::VERTICAL:
		for(int i = 0; i < COLUMNS; ++i) {
			if(getSlot(0, i) == getSlot(1, i) && getSlot(0, i) == getSlot(2, i) )
				if(getSlot(0, i) == ans)
				return true;
		}

	case Board::DIAGONAL:
		if(getSlot(0, 0) == getSlot(1, 1) && getSlot(0, 0) == getSlot(2, 2) )
			if(getSlot(0, 0) == ans)
				return true;

		if(getSlot(0, 2) == getSlot(1, 1) && getSlot(0, 2) == getSlot(2, 0) )
			if(getSlot(0, 2) == ans)
				return true;
	}
	return false;
}
