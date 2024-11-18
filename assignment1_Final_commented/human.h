#ifndef HUMAN_H_
#define HUMAN_H_

#include "player.h"


// this is a derived class from the player class which inherits from the player class
class Human : public Player {
    public: 
    // function that handles the moves, the ovveride indicated that this function
    // overrides a virtual function from the Player class
        void playerMove(char player, int& x, int& y, TicTacToe *board) override;

};

// function that will handles the moves of the human player
// passes by reference the parameters x and y which will be used to determine
// the new position of the board after the player does their move
// also passes a pointer to the current boarrd that is being played on
void Human::playerMove(char player, int& x, int& y, TicTacToe *board){
    int row, col;

    showTurn(player);

    bool validMove = true;

    // keep asking for a move if the  move is not valid, taken place or out of bounds
    do {    
        if(!validMove){
            cout << "Invalid move. you can only enter a number between 1-3 and at an emply position. Try again\n";
        }

        cout << "enter row: ";
        cin >> row;
        cout << "enter col: ";
        cin >> col;

        validMove = board->isValidMove(row - 1, col - 1);

    } while(!validMove);

    // updates x and y after player does their inputs
    x = row - 1;
    y = col - 1;
}


#endif