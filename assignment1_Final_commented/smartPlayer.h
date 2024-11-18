#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

#include "player.h"
#include "minimax.h"

// similar case to the humanPlayer class but instead of manual 
// this class uses the minimax algorithm to make decisions
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
        // a boolean to see if the board that is being played on is empty or not
        bool emptyBoard = checkBoardEmpty(board);
        
        // if the board is not empty then the minimax algorithm is used to find the best move
        // otherwise a position is chosen randomly to not have a repeat patter by minimax
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

// goes over every row and every colum to see if there are any empty spaces
// if all spaces are empty then it means the board is empty
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