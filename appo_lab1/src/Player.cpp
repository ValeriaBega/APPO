#include "Player.h"
#include "board.h"

// ---------------------OriginalPlayer-------------------------//
void Player::setMark(char ans) {
	mark = ans;
}

char Player::getMark() const {
	return mark;
}

const std::string & Player::getName() const {
	return name;
}
// ---------------------HumanPlayer-------------------------//

HumanPlayer::HumanPlayer(const std::string &_name) {
	name = _name;
}

HumanPlayer::HumanPlayer() {
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
}

int HumanPlayer::makeMove() {
	int temp;

	do {
		temp = getInt();
		if(temp <= 0 || temp > ROWS * COLUMNS)
			std::cout << temp << " is not between 1 and 9. Enter again: ";

	}while(temp <=0 || temp > ROWS * COLUMNS);

	return --temp;
}

// ---------------------ComputerPlayer-------------------------//

ComputerPlayer::ComputerPlayer(): pBoard(0) {
	name = "Computer";
}

int ComputerPlayer::makeMove() {
	srand((unsigned)time(0));

	Board temp = *pBoard;

	char myMark = getMark();
	char otherMark;
	if(myMark == X) {
       otherMark = O;
	}
	else {
        otherMark = X;
	}

	//return a random number
	int randNo;
	do {
		randNo = rand() % (ROWS * COLUMNS);

	} while(temp.getSlot(randNo) != EMPTY);

	return randNo;
}

void ComputerPlayer::setBoard(const Board *const board) {
	pBoard = board;
}

