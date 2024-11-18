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

void NBTicTacToe::displayBoards(int currentBoardX, int currentBoardY, TicTacToe grid[3][3]){
    char wall;

    for(int row = 0; row < 3; row++){

        horizontalLine(row, currentBoardX, currentBoardY);
        cout << endl;

        for(int innerRow = 0; innerRow < 3; innerRow++){

            for(int  innerCol = 0; innerCol < 3; innerCol++){

                if(row == currentBoardX && innerCol == currentBoardY) {
                    cout << "* "; 
                    wall = '*';
                } else {
                    cout << "| ";
                    wall = '|';
                }

                grid[row][innerCol].displayRow(innerRow, wall);

            }
            cout << endl;

            if(innerRow != 2){

             for(int i = 0; i < 3; i++){
                    if(row == currentBoardX && i == currentBoardY) {
                        cout << "*---|---|---* "; 
                    } else {
                        cout << "|---|---|---| ";
                    }
                }
                cout << endl;
                
            }
        }

        horizontalLine(row, currentBoardX, currentBoardY);
        cout << endl;
    }
}


void  NBTicTacToe::horizontalLine(int row, int currentBoardX, int currentBoardY){

    for(int i = 0; i < 3; i++){

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