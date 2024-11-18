#ifndef MINIMAX_H_
#define MINIMAX_H_

#include "TicTacToe.h"
#include <limits>
#include <iostream>

class Minimax {
    private:
    // Private recursive function that implements the minimax algorithm
        // Takes in a TicTacToe board, depth of the recursion, and a boolean to indicate if it's the minimaxing player's turn
        int minimax(TicTacToe *board, int depth, bool isManimaxingPlayer);

    public:
     // Public function to invoke the Minimax algorithm to find the best move
        void useMinimax(TicTacToe *board, int& x, int& y);
};

// This function finds the best move using the minimax algorithm
// It evaluates every possible move and selects the one with the highest score for the AI
void Minimax::useMinimax(TicTacToe *board, int& x, int& y){
    int bestScore =  std::numeric_limits<int>::min();   // Initialize the best score to negative infinity
    int bestX, bestY;   // Variables to store the coordinates of the best move

    // Iterate over all the cells of the TicTacToe board
    for(int i = 0; i < BOARDSIZE; i++){
        for(int j = 0; j < BOARDSIZE; j++){

            // Check if the current cell is empty
            if(board->getCell(i, j) == 0){

                // Make a hypothetical move for the AI
                board->addMove(i, j, -1);

                 // Call the minimax function to evaluate this move
                int score = minimax(board, 0, false);

                // Undo the move
                board->addMove(i, j, 0);

                // If the move has a higher score than the current best score, update the best score and move coordinates
                if(score > bestScore){
                bestScore = score;
                bestX = i;
                bestY = j;
                }
            }
        }
    }

    // Set the output parameters x and y to the best move's coordinates
    x = bestX;
    y = bestY;

}

// Recursive implementation of the Minimax algorithm
int Minimax::minimax(TicTacToe *board, int depth, bool isManimaxingPlayer){

    // Check the status of the game
    int status = board->gameStatus();

    // If the minimizing player (opponent) has won, return a negative score adjusted by depth (to prioritize faster wins for the opponent)
    if(status == 1){
        return -10 + depth;
    }

    // If the maximizing player (smartPlayer) has won, return a positive score adjusted by depth (to prioritize faster wins for the AI)
    else if(status == -1){
        return 10 - depth;
    }

    // If the game is a draw, return 0
    else if(status == 2){
        return 0;
    }

    // If it's the maximizing player's turn (smartPlayers's turn)
    if(isManimaxingPlayer) {
        int bestScore = std::numeric_limits<int>::min();    // Initialize the best score to negative infinity
        for(int i = 0; i < BOARDSIZE; i++) {
            for (int j = 0; j < BOARDSIZE; j++){

                 // Check if the cell is empty
                if(board->getCell(i, j) == 0) {

                    // Make a hypothetical move for the smartPlayer
                    board->addMove(i, j, -1);

                    // Recursively call minimax for the next move (opponent's turn)
                    int score = minimax(board, depth + 1, false);

                    // Undo the move
                    board->addMove(i, j, 0);

                    // Update the best score if the new score is greater
                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;   // Return the best score for this move
    }

    // If it's the minimizing player's turn (opponent's turn)
    else {
        int  bestScore = std::numeric_limits<int>::max();   // Initialize the best score to positive infinity
        for(int i = 0; i < BOARDSIZE; i++){
            for(int j = 0; j < BOARDSIZE; j++){

                // Check if the cell is empty
                if(board->getCell(i, j) == 0) {

                    // Make a hypothetical move for the human player 
                    board->addMove(i, j, 1);

                    // Recursively call minimax for the next move (AI's turn)
                    int score = minimax(board, depth + 1, true);

                    // Undo the move
                    board->addMove(i, j, 0);

                    // Update the best score if the new score is smaller
                    bestScore = std::min(bestScore, score);
                }
            }

        }
        return bestScore;   // Return the best score for this move
    }
}


#endif