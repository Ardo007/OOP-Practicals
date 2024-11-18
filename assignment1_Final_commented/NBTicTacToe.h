#ifndef GAME_H_
#define GAME_H_

#include "TicTacToe.h"
#include "Coordinate.h"



class NBTicTacToe {
    public:
        void displayBoards(int, int, TicTacToe grid[3][3]);
        void horizontalLine(int, int, int);
    private:
};

// main display function to display the board
void NBTicTacToe::displayBoards(int currentBoardX, int currentBoardY, TicTacToe grid[3][3]){
    // the wall of each board, will be used to create the selected board and regular boards
    char wall;

    // main row of the nine boards
    for(int row = 0; row < 3; row++){

        // horizontal divider between main board rows
        horizontalLine(row, currentBoardX, currentBoardY);
        cout << endl;

        // inner row of the nine boards
        for(int innerRow = 0; innerRow < 3; innerRow++){

            // columns of each individual row
            for(int  innerCol = 0; innerCol < 3; innerCol++){

                // to print * for the current board
                if(row == currentBoardX && innerCol == currentBoardY) {
                    cout << "* "; 
                    wall = '*';
                } else {
                    cout << "| ";
                    wall = '|';
                }

                // prints one row of one board
                grid[row][innerCol].displayRow(innerRow, wall);
            }
            cout << endl;

            // to add a divider between each row for individual boards
            if(innerRow != 2){
             for(int i = 0; i < 3; i++){

                    // to print * for current board
                    if(row == currentBoardX && i == currentBoardY) {
                        cout << "*---|---|---* "; 
                    } else {
                        cout << "|---|---|---| ";
                    }
                }
                cout << endl;
            }
        }

        // horizontal divider between main board rows
        horizontalLine(row, currentBoardX, currentBoardY);
        cout << endl;
    }
}


// function to print the horizontal divider
void  NBTicTacToe::horizontalLine(int row, int currentBoardX, int currentBoardY){
    for(int i = 0; i < 3; i++){
        // to print * for the current board
        if(row == currentBoardX && i == currentBoardY){
            for(int j = 0; j < 13;  j++){
                cout << "*";
            }
            cout << ' ';
        } else {
            for(int j = 0; j < 13;  j++){
                cout << "-";
            }
            cout << ' ';
        }
    }
}





#endif /* GAME_H_ */