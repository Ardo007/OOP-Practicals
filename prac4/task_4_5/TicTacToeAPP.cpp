/*
 * TicTacToeAPP.cpp
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "TicTacToe.h"
#include "NBTicTacToe.h"

int main() {
	NBTicTacToe game(1, 1);
	game.play();

	return 0;

}


