#include "Referee.h"



Referee::Referee(){}

// Note-to-self: player1 is Human and player 2 is computer
Player* Referee::refGame(Player* player1, Player* player2){
    Move* player1_move = player1->makeMove();
    Move* player2_move = player2->makeMove();
    int result = player1_move->compareMoves(player2_move);
    if(result == 1) return player1; // player1 wins
    else if(result == 2) return player2; // player1 loses => player2 wins
    else return nullptr; // it's a tie
}