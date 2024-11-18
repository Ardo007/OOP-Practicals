//Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayBoard(int board[][3]) {
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

bool isValidMove(int board[][3], int x, int y) {
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == 0) //Add your code here
		return true;
	else{
		cout << "not valid move try again\n";
		return false;
	}
}

bool getXOMove(int board[][3], int noOfMoves, int &x, int &y) {

	if (noOfMoves >= 9)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(board, row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	return true;
}

void addMove(int board[][3], int x, int y, int player) {
	board[x][y] = player;
}

int gameStatus(int board[][3], int &noOfMoves) {
//Write your code here to check if the game has been in a win status or a draw status
//Check rows for a win
	// if(board[0][0] != 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2]){
	// 	return board[0][0];
	// }
	// else if(board[1][0] != 0 && board[1][0] == board[1][1] && board[1][1] == board[1][2]){		// the way the for loop was made
	// 	return board[1][0];																			// checking the content of each row one by one
	// }																							// and seeing if it matches each other then it means
	// else if(board[2][0] != 0 && board[2][0] == board[2][1] && board[2][1] == board[2][2]){		// which ever player is in that row wins 
	// 	return board[2][0];
	// }

//Add your code here
	for(int i = 0; i < 3; i++){
		if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}
//Check columns for a win

//Add your code here
	for(int i = 0; i < 3; i++){
		if(board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];																	// same concept as checking for row but the column is i 
		}																						// so we can check each column 
	}
//Check diagonals for a win

//Add your code here

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

int main() {
	int board[3][3];
	int noOfMoves;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;

	int player = 1;

	displayBoard(board);
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		getXOMove(board, noOfMoves, x, y);

		addMove(board, x, y, player);
		noOfMoves++;
		displayBoard(board);

		done = gameStatus(board, noOfMoves);
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 0;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return 0;
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


