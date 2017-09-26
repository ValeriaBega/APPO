#include <iostream>

#include "functions.h"
#include "Game.h"

using namespace std;

int getNumPlayers();

int main()
{
	cout << "\tTic-Tac-Toe Game\n\n";
	cout << "\tHave a pleasant time\n\n";

	Game game(getNumPlayers());
	game.Instructions();
	game.Play();

	cin.get();
	return 0;
}

int getNumPlayers()
{
	cout << "How many players will be? 1/2: ";
	int numPlayers;
	do
	{
		numPlayers = getInt();

		if(numPlayers != 1 && numPlayers != 2)
			cout << "1 or 2, not " << numPlayers << "!\n";

	}while(numPlayers != 1 && numPlayers != 2);
	return numPlayers;
}
