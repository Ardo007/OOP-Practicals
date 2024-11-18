#ifndef HUMAN_H_
#define HUMAN_H_

#include "player.h"


class Human : public Player {
    public: 
        void playerMove(char player, int& x, int& y, TicTacToe *board) override;

};

void Human::playerMove(char player, int& x, int& y, TicTacToe *board){
    int row, col;

    showTurn(player);

    bool validMove = true;

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

    x = row - 1;
    y = col - 1;
}


#endif