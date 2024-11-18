 /*
 * TicTacToe.h
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */
#ifndef TICTACTOE_H_
#define TICTACTOE_H_

const int BOARDSIZE = 3;

class TicTacToe {
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;
public:
	TicTacToe();
	bool isValidMove(int, int);
	int getNoOfMoves();
	void setNoOfMoves(int);
	void addMove(int, int, int);
	int gameStatus();
	void displayRow(int);
	void displayBoard();

};


void TicTacToe::displayRow(int row){
	for(int i = 0; i < 3; i++){
		char symbol;
		if(board[row][i] == 1){
			symbol = 'X';
		}
		else if(board[row][i] == -1){
			symbol = 'O';
		}
		else {
			symbol = '_';
		}
		cout << symbol;
		if((i+1)%3==0 && i!=8){
			cout << " ";
		}
	}
}



//getter
int TicTacToe::getNoOfMoves(){
	return noOfMoves;
}

//setter
void TicTacToe::setNoOfMoves(int noOfMoves){
	this->noOfMoves = noOfMoves;
}


TicTacToe::TicTacToe() {//How to call this function?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

// void TicTacToe::displayBoard() {//Where to get the board data?
	
// 	for (int i = 0; i < 3; i++) {
// 		cout << " ";
// 		for (int j = 0; j < 3; j++) {
// 			char playerSymbol = ' ';
// 			if (board[i][j] == 1)
// 				playerSymbol = 'X';
// 			else if (board[i][j] == -1)
// 				playerSymbol = 'O';
// 			cout << setw(3) << playerSymbol;
// 			if (j != 2)
// 				cout << " |";
// 		}
// 		cout << endl;
// 		if (i != 2)
// 			cout << " ____|____|____" << endl << "     |    |    " << endl;
// 	}
// 	// cout << endl;
// }

bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == 0) //Add your code here)
		return true;
	else
		return false;
}



void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	board[x][y] = player;
}

int TicTacToe::gameStatus() {//Add your code to complete the program
//row win
	for(int i = 0; i < 3; i++){
		if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}
//column win
	for(int i = 0; i < 3; i++){
		if(board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];																	// same concept as checking for row but the column is i 
		}																						// so we can check each column 
	}

//diagonal win
	if(board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return board[0][0];
	}
	if(board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];
	}


	if (noOfMoves >= 9)
		return 2;

	return 0;
}



#endif /* TICTACTOE_H_ */


