#include "Game.h"
#include "board.h"
#include "Player.h"

Game::Game(int numPlayers) {
    board = new Board();

	assert(numPlayers == 1 || numPlayers == 2);

	if(numPlayers == 1) {
		p1 = new HumanPlayer();
		p2 = new ComputerPlayer();
		dynamic_cast <ComputerPlayer*> (p2)->setBoard(board);
	}
	else
	{
		p1 = new HumanPlayer();
		p2 = new HumanPlayer();
	}

	std::cout << "\n";
}

Game::~Game() {
	//free the memory allocated by the Player pointers
	delete p1;
	delete p2;

	//and the board
	delete board;
}

void Game::Instructions() {
    std::cout << "Welcome to Tic Tac Toe!!\n\n";

	board->setSlot(0, '1');
	board->setSlot(1, '2');
	board->setSlot(2, '3');

	board->setSlot(3, '4');
	board->setSlot(4, '5');
	board->setSlot(5, '6');

	board->setSlot(6, '7');
	board->setSlot(7, '8');
	board->setSlot(8, '9');

	std::cout << "You should enter a value from 1 to 9 to indicate where you want to insert your mark:\n\n";
	std::cout << *board;

	board->Clear();
}

void Game::Play() {
    setMarks();

	Player *currentPlayer = 0;

	if(p1->getMark() == X)
		currentPlayer = p1;
	else
		currentPlayer = p2;

	//THE GAME LOOP
	int choice;
	while(Win() == EMPTY && !Tie()) {
		// if it's a human player that's playing, display the text
		if(dynamic_cast <HumanPlayer*> (currentPlayer))
			std::cout << currentPlayer->getName() << ", it's your turn. [" << currentPlayer->getMark() << "] 1-9: ";

		// loop until the player who plays chooses a field which is empty
		do {
			choice = currentPlayer->makeMove();
			if(board->getSlot(choice) != EMPTY)
				std::cout << "Choose another place\n";

		} while(board->getSlot(choice) != EMPTY);

		std::cout << currentPlayer->getName() << " chooses " << choice + 1 << ".\n\n";

		board->setSlot(choice, currentPlayer->getMark());
		std::cout << *board;

		// it's the turn of the other player
		if(currentPlayer == p1)
			currentPlayer = p2;
		else
			currentPlayer = p1;
	}

	if(Win() == p1->getMark())
		std::cout << p1->getName() << " wins! Hope you, " << p2->getName() << " will win next time\n";
	if(Win() == p2->getMark())
		std::cout << p2->getName() << " wins! Hope you, " << p1->getName() << " will win next time\n";
}

//returns true if it's a tie
bool Game::Tie() const
{
	//if the fields that do not contain EMPTY are ROWS * COLUMNS and no one has won, it's a tie
	if(board->numFreeSlots(EMPTY) == ROWS * COLUMNS)
	{
		std::cout << "Congratulations! It's a tie!!!\n";
		return true;
	}

	return false;
}

char Game::Win() const
{
	for(int i = Board::HORIZONTAL; i <= Board::DIAGONAL; ++i)
	{
		// i here needs to be casted to Board::DIRECTION
		if(board->success((Board::DIRECTION)i, p1->getMark()))
			return p1->getMark();
		if(board->success((Board::DIRECTION)i, p2->getMark()))
			return p2->getMark();
	}

	return EMPTY;
}

void Game::setMarks()
{
	srand((unsigned)time(0));
	int p1First = rand() % 2; // if 1, p1 plays first. if 0, p2 plays first (gets X, which goes first)

	if(p1First)
	{
		std::cout << p1->getName() << " plays first. [X]\n\n";
		p1->setMark(X);
		p2->setMark(O);
	}
	else
	{
		std::cout << p2->getName() << " plays first. [X]\n\n";
		p1->setMark(O);
		p2->setMark(X);
	}
}
