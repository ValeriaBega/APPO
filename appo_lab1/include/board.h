#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cassert>
#include "constants.h"
#include "functions.h"

class Board
{
    public:
        //constructor
        Board();
        //friend function for ostrem operator
        friend std::ostream &operator <<(std::ostream &os, const Board &b);
        //function to set all slots empty
        void Clear();
        //setter
        void setSlot(int row, int column, char ans);
        void setSlot(int index, char ans);
        //getters
        char getSlot(int row, int column) const;
        char getSlot(int index) const;
        //find out number of free slots(which don't contain any character)
        int numFreeSlots(char ans);
        //directions for game
        enum DIRECTION {HORIZONTAL, VERTICAL, DIAGONAL};
        //returns if one of characters is present 3 times in any directions
        bool success(DIRECTION direction, char ans);

    private:
        char table[COLUMNS][ROWS];
};

#endif // BOARD_H
