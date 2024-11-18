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



// main funtion to play the game
void  NBGame::play(){

    // to display the menu and hold the game option 
    // that was selected by the user to determine the players in the game
    int gameOption = menu.displayMenu();

    // integer to determine player turns 
    int player = 1;

    cout << "-----------------------------------------------------------------------" << endl;

    // to not display the board if the user selects to quit the game
    if(gameOption !=5)
        displayBoard();

    // determine when the game ends and who wins
    int done = 0;

    // to play the game if there is no winner or a draw and if the player did not select the quit game option in the menu
    while(done == 0 && gameOption !=5){
        // hold player moves
        int x, y;

        // process the play moves
        playerMoves(x, y, player, gameOption);


        cout << "-----------------------------------------------------------------------" << endl;

        // add the move that the player did on the current board being played on 
        grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
        
        // increase the number of moves for that board to know when it reaches a draw, aka 9 moves
        grid[currentBoard.x][currentBoard.y].setNoOfMoves(grid[currentBoard.x][currentBoard.y].getNoOfMoves() - 1);

        // display the board again after player input their move
        displayBoard();

        // update the game status to see if there is a winner
        done = grid[currentBoard.x][currentBoard.y].gameStatus();

        // determine who won through the done integer
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

        // change the board being played on to the inputed moves
        changeBoard(x, y);

        cout << "-----------------------------------------------------------------------" << endl;
        cout << "current Board is " <<  currentBoard.x + 1 << " , " << currentBoard.y + 1 << endl;

        // display the board that is current being played on
        displayBoard();

        // switch players after a turn
        if(player == 1){
            player = -1;
        }
        else {
            player = 1;
        }
    }
}


// handle player moves
void NBGame::playerMoves(int& x, int& y, int player, int gameOption) { 
    // player 1 is X and player 2 is O
    char playerSymbol = (player == 1) ? 'X' : 'O';

    // get the board being played on
    TicTacToe *currentBoardPlayingOn = &grid[currentBoard.x][currentBoard.y];

    // the players to be in the game according to the game option selected by the player
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



// calls the displayBoards function from NBTicTacToe
void NBGame::displayBoard(){
    nbTicTacToe.displayBoards(currentBoard.x, currentBoard.y, grid);
}


// updates the board position after a turn
// checks if the boards being switched too is not full, aka all spots taken
// if it is taken then it switched to another random board
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