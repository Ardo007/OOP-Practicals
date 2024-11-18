#ifndef PLAYER_H_
#define PLAYER_H_

#include "TicTacToe.h"
#include "NBGame.h"

#include <iostream>
using namespace std;

// parent class for all players involved, this is an abstract base class
class Player{
    private:

    public:
       // a virtual function to be implemented by derived classes
       virtual void playerMove(char player, int& x, int& y, TicTacToe *board) = 0;
       
       // to ensure the correct destuctor is being called for the derived classes
       virtual ~Player() {} 
    
       // shows the turn of the current player
       void showTurn(char);

};

void Player::showTurn(char player){

    cout << "********************\n";
    cout << "It is " << player << "'s turn\n";
    cout << "********************\n";
}



#endif