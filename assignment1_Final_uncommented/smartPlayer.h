#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

#include "player.h"
#include "minimax.h"

class SmartPlayer : public Player {
    public:
        void playerMove(char player, int& x, int& y, TicTacToe *board) override;

    private:
        Minimax minimax;
        bool checkBoardEmpty(TicTacToe *board);
};

void SmartPlayer::playerMove(char player, int& x, int& y, TicTacToe *board){

    srand(time(0));


    showTurn(player);

    bool validMove = true;

    do{
        bool emptyBoard = checkBoardEmpty(board);
        
        if(!emptyBoard){
            minimax.useMinimax(board, x, y);
        }
        else {
            x = rand() % 3;
            y = rand() % 3;
        }

        validMove = board->isValidMove(x, y);
    }while(!validMove);

}

bool SmartPlayer::checkBoardEmpty(TicTacToe *board){
    for(int i = 0; i < BOARDSIZE; i++){
        for(int j = 0; j < BOARDSIZE; j++){
            if(board->getCell(i, j) != 0){
                return false;
            }
        }
    }
    return true;
}

#endif