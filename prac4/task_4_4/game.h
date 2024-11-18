#ifndef GAME_H_
#define GAME_H_



#include <iostream>
using namespace std;




#include "TicTacToe.h"


class Game {
    public:
        void play();
        void getXMove(char player, int&, int&);
        void getOMove(char player, int&, int&);
    private:
        TicTacToe board;
};

void Game::getXMove(char player, int& x, int& y) {
    int row, col; 

    bool validMove = true;
    srand(time(NULL));

    do{
        row = rand() % 3;
        col = rand() % 3;
        if(board.isValidMove(row, col) == false){
            cout << "not a valid move\n";
            cout << "you tried setting at a taken spot row: " << row + 1 << "and col: " << col + 1 << '\n';
        }

        validMove = board.isValidMove(row, col);
    }while(!validMove);
    x = row;
    y = col;
}


void Game::getOMove(char player, int& x, int& y) {
    int row, col;

    bool validMove = true;

    do{
        cin >> row >> col;
        cout << endl;
        if(board.isValidMove(row - 1, col - 1) == false){
            cout << "not valid move try again\n";
			cout << "you tried placing in a taken spot at row: " << row << " col: " << col << endl;
        }

        validMove = board.isValidMove(row - 1, col - 1);
    }while(!validMove);
    x = row - 1;
    y = col - 1;

}

void Game::play(){
    int player = 1;

    board.displayBoard();
    int done = 0;

    while(done == 0){
        char playerSymbol = (player == 1) ? 'X' : 'O';
        int x, y;

        if(player == 1){
            getXMove(playerSymbol, x, y);
        }
        else{
            cout << "player O enter your move (row column): ";
            getOMove(playerSymbol, x, y);
        }

        board.addMove(x, y, player);
        board.setNoOfMoves(board.getNoOfMoves() + 1);
        board.displayBoard();

        done = board.gameStatus();

        if(done == 1){
            cout << "X Won!" << endl;
            break;
        }
        else if(done == -1){
            cout << "O Won!" << endl;
            break;
        }
        else if(done == 2){
            cout << "Draw!" << endl;
            break;
        }

        if(player == 1)
            player = -1;
        else
            player = 1;
    }

}



#endif /* GAME_H_ */