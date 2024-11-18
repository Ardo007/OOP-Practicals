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
	void displayRow(int, char);
	int getCell(int, int);

};

void TicTacToe::displayRow(int row, char wall){
	for(int i = 0; i < 3; i++){
		char symbol;
		if(board[row][i] == 1){
			symbol = 'X';
		}
		else if(board[row][i] == -1){
			symbol = 'O';
		}
		else {
			symbol = ' ';
		}
		cout << symbol;
		if(i == 2){
			cout << " " << wall << " ";
		}
		else {
			cout << " | ";
		}
	}
}

int TicTacToe::getCell(int x, int y){
	return board[x][y];
}



int TicTacToe::getNoOfMoves(){
	return noOfMoves;
}

void TicTacToe::setNoOfMoves(int noOfMoves){
	this->noOfMoves = noOfMoves;
}


TicTacToe::TicTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}


bool TicTacToe::isValidMove(int x, int y) {
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == 0) 
		return true;
	else
		return false;
}



void TicTacToe::addMove(int x, int y, int player) {
	board[x][y] = player;
}

int TicTacToe::gameStatus() {
	for(int i = 0; i < 3; i++){
		if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}
	for(int i = 0; i < 3; i++){
		if(board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];																	 
		}																						
	}

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


