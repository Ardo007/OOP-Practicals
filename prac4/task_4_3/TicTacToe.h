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
	bool getXMove(int&, int&);
	bool getOMove(int&, int&);
	void addMove(int, int, int);
	int gameStatus();
	int play();
	void displayBoard();
};

TicTacToe::TicTacToe() {//How to call this function?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

void TicTacToe::displayBoard() {//Where to get the board data?
	cout << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}

bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == 0) //Add your code here)
		return true;
	else
		return false;
}



bool TicTacToe::getXMove(int &x, int &y){
	if (noOfMoves >= 9){
		return false;
	}

	srand(time(NULL));

	int row, col;
	do {
			row = rand() % 3;
			col = rand() % 3;
			if(isValidMove(row, col) == false){
				cout << "not valid move try again\n";
				cout << "you tried placing in a taken spot at row: " << row + 1 << " col: " << col + 1 << endl;
			}
	} while (!isValidMove(row, col));
	x = row ;
	y = col ;

	return true;

}


bool TicTacToe::getOMove(int &x, int &y){
	if (noOfMoves >= 9){
		return false;
	}

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
		if(isValidMove(row - 1, col - 1) == false){
			cout << "not valid move try again\n";
			cout << "you tried placing in a taken spot at row: " << row << " col: " << col << endl;
		}
		
	} while (!isValidMove(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	
	return true;
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

int TicTacToe::play() {//What is the counterpart of this function in the original code

	int player = 1;

	displayBoard();
	int done = 0;
	while (done == 0) {
		int x, y;

		if(player == 1){
			getXMove(x, y);
		}
		else{
			cout << "player O enter your move (row column): ";
			getOMove(x, y);
		}


		addMove(x, y, player);
		noOfMoves++;
		displayBoard();

		done = gameStatus();
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 1;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return -1;
		} else if (done == 2) {
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

	return 0;
}



#endif /* TICTACTOE_H_ */


