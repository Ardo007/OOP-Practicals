#ifndef PLAYER_H_
#define PLAYER_H_

#include "TicTacToe.h"
#include "NBGame.h"

#include <iostream>
using namespace std;

class Player{
    private:

    public:
       virtual void playerMove(char player, int& x, int& y, TicTacToe *board) = 0;       
       virtual ~Player() {} 
       void showTurn(char);

};

void Player::showTurn(char player){

    cout << "********************\n";
    cout << "It is " << player << "'s turn\n";
    cout << "********************\n";
}



#endif