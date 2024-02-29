#include "Referee.h"



Referee::Referee(){}

// Note-to-self: player1 is Human and player 2 is computer
Player* Referee::refGame(Player* player1, Player* player2){
    char player1_move = player1->makeMove();
    char player2_move = player2->makeMove();
    if (player1 -> getName() == "Computer"){ // computer's move is always 'R'
        if (player1_move == 'P') return player2;
        else if (player2_move == 'S') return player1; // player2's move is S so player2 lost, return player 1
        else return nullptr; // it's a tie
    }
    else{ // player1 is a human player, player2 is a computer player: 'R'
        if (player1_move == 'S') return player2; // player2's move is 'S'
        else if(player1_move == 'P') return player1; // player1's move is 'P'
        else return nullptr; // it's a tie
    }
}