#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <ctime>
#include <stdlib.h>
#include "constants.h"
#include "functions.h"
#include "board.h"

class Board; //this class is declared because it will be used for ComputerPlayer class
class Player //this is a generic class(virtual)
{
    public:
	virtual int makeMove() = 0;
    //getter
	const std::string & getName() const;

	void setMark(char ans);
	char getMark() const;

protected:
	char mark; //marks are X or O
	std::string name;
};
//----------------------------------------
class HumanPlayer : public Player {
public:
	//constructors
	HumanPlayer(const std::string &_name);
	HumanPlayer();

	virtual int makeMove();
};
//----------------------------------------
class ComputerPlayer : public Player {
public:
    //constructor
	ComputerPlayer();
	virtual int makeMove();

	void setBoard(const Board *const board);

private:
	const Board *pBoard;
};
//----------------------------------------

#endif // PLAYER_H
