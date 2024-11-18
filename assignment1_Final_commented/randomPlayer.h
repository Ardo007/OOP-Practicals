#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "player.h"

// similar case to the humanPlayer class but instead of manual 
// inputs it generates random numbers to determine the position 
// the move will be played on
class RandomPlayer : public Player {
    public:
        void playerMove(char player, int& x, int& y, TicTacToe *board) override;
};

void RandomPlayer::playerMove(char player, int& x, int& y, TicTacToe *board) {
    int row, col;

    srand(time(0));


    showTurn(player);

    bool validMove = true;

    do {
        row = rand() % 3;
        col = rand() % 3;

        validMove = board->isValidMove(row, col);

    } while(!validMove);

    x = row;
    y = col;
}



#endif