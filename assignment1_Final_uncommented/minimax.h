#ifndef MINIMAX_H_
#define MINIMAX_H_

#include "TicTacToe.h"
#include <limits>
#include <iostream>

class Minimax {
    private:
        int minimax(TicTacToe *board, int depth, bool isManimaxingPlayer);

    public:
        void useMinimax(TicTacToe *board, int& x, int& y);
};

void Minimax::useMinimax(TicTacToe *board, int& x, int& y){

    int bestScore =  std::numeric_limits<int>::min();   
    int bestX, bestY;   

    for(int i = 0; i < BOARDSIZE; i++){

        for(int j = 0; j < BOARDSIZE; j++){

            if(board->getCell(i, j) == 0){

                board->addMove(i, j, -1);

                int score = minimax(board, 0, false);

                board->addMove(i, j, 0);

                if(score > bestScore){
                bestScore = score;
                bestX = i;
                bestY = j;
                }
            }
        }
    }

    x = bestX;
    y = bestY;

}

int Minimax::minimax(TicTacToe *board, int depth, bool isManimaxingPlayer){

    int status = board->gameStatus();

    if(status == 1){
        return -10 + depth;
    }

    else if(status == -1){
        return 10 - depth;
    }

    else if(status == 2){
        return 0;
    }

    if(isManimaxingPlayer) {

        int bestScore = std::numeric_limits<int>::min();    

        for(int i = 0; i < BOARDSIZE; i++) {

            for (int j = 0; j < BOARDSIZE; j++){

                if(board->getCell(i, j) == 0) {

                    board->addMove(i, j, -1);

                    int score = minimax(board, depth + 1, false);

                    board->addMove(i, j, 0);

                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;   
    }


    else {
        int  bestScore = std::numeric_limits<int>::max();   

        for(int i = 0; i < BOARDSIZE; i++){

            for(int j = 0; j < BOARDSIZE; j++){

                if(board->getCell(i, j) == 0) {

                    board->addMove(i, j, 1);

                    int score = minimax(board, depth + 1, true);

                    board->addMove(i, j, 0);

                    bestScore = std::min(bestScore, score);
                }
            }

        }
        return bestScore;   
    }
}


#endif