#ifndef GAME_H
#define GAME_H

#include <cassert> //debugging
#include <iostream>
#include <string>
#include <ctime>
#include "constants.h"

//class declarations
class Board;
class Player;
class HumanPlayer;
class ComputerPlayer;

class Game {
    public:
        //constructor
        Game(int numPlayers = 1);
        //destructor
        ~Game();

        void Play();
        void Instructions();

        bool Tie() const;                 // true if it's a tie
        char Win() const;                  // returns the winning mark if there's a winner, or empty if there isn't a winner

    private:
        void setMarks();                      // sets marks X for p1 and O for p2
        Board *board;
        Player *p1, *p2;
};

#endif // GAME_H
