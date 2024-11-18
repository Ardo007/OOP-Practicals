#ifndef NBGAME_H_
#define NBGAME_H_

#include "NBTicTacToe.h"
#include "TicTacToe.h"
#include "Coordinate.h"
#include "player.h"
#include "human.h"
#include "randomPlayer.h"
#include "smartPlayer.h"
#include "menu.h"

class NBGame{
    private:

        TicTacToe grid[3][3];

        TicTacToe board;

        Coordinate currentBoard;
        NBTicTacToe nbTicTacToe;

        Human human;
        RandomPlayer randomPlayer;
        SmartPlayer smartPlayer;

        Menu menu;


    public:
        NBGame(){
            srand(time(0));
            currentBoard.x = rand() % 3;
            currentBoard.y = rand() % 3;
        }

        void play();
        void displayBoard();
        void playerMoves(int&, int&, int, int);
        void changeBoard(int x, int y);
};



void  NBGame::play(){

    int gameOption = menu.displayMenu();

    int player = 1;

    cout << "-----------------------------------------------------------------------" << endl;

    if(gameOption !=5)
        displayBoard();

    int done = 0;

    while(done == 0 && gameOption !=5){
        int x, y;

        playerMoves(x, y, player, gameOption);


        cout << "-----------------------------------------------------------------------" << endl;

        grid[currentBoard.x][currentBoard.y].addMove(x, y, player);        
        grid[currentBoard.x][currentBoard.y].setNoOfMoves(grid[currentBoard.x][currentBoard.y].getNoOfMoves() - 1);
        displayBoard();

        done = grid[currentBoard.x][currentBoard.y].gameStatus();

        if(done == 1){
            cout << "X Won!\n";
            break;
        }
        else if(done == -1){
            cout << "O Won!\n";
            break;
        }
        else if (done == 2) {
            cout << "Draw!\n";
            break;
        }

        changeBoard(x, y);

        cout << "-----------------------------------------------------------------------" << endl;
        cout << "current Board is " <<  currentBoard.x + 1 << " , " << currentBoard.y + 1 << endl;

        displayBoard();

        if(player == 1){
            player = -1;
        }
        else {
            player = 1;
        }
    }
}


void NBGame::playerMoves(int& x, int& y, int player, int gameOption) { 
    char playerSymbol = (player == 1) ? 'X' : 'O';

    TicTacToe *currentBoardPlayingOn = &grid[currentBoard.x][currentBoard.y];

    switch (gameOption)
    {
    case 1:
        if(player == 1){
            human.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        else {
            human.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        break;
    case 2:
        if(player == 1){
            human.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        else {
            randomPlayer.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        break;
    case 3:
        if(player == 1){
            human.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        else {
            smartPlayer.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        break;
    case 4:
        if(player == 1){
            randomPlayer.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        else {
            smartPlayer.playerMove(playerSymbol, x, y, currentBoardPlayingOn);
        }
        break;
    }

}



void NBGame::displayBoard(){
    nbTicTacToe.displayBoards(currentBoard.x, currentBoard.y, grid);
}


void NBGame::changeBoard(int x, int y){
    bool validChange = board.isValidMove(x, y);

    while(!validChange){
        x = rand() % 3;
        y = rand() % 3;

        validChange = board.isValidMove(x, y);
    }

    if(validChange){
        currentBoard.x = x;
        currentBoard.y = y;
    }
}



#endif