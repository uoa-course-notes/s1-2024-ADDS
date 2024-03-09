#include <iostream>
// Include our 'main' entities
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Referee.h"

// Include the classic RSP
#include "Rock.h"
#include "Scissor.h"
#include "Paper.h"

// Include additional moves
#include "Ninja.h"
#include "Robot.h"
#include "Pirate.h"
#include "Zombie.h"
#include "Monkey.h"


int main(int argc, char** argv){
    Move* move1 = new Ninja();
    Player* player1 = new Human("Mei", move1);
    // if (player1 -> makeMove() == nullptr) player1 -> setMove(move1);
    
    Move* move2 = new Robot();
    Player* player2 = new Human("Seth", move2);
    // if (player2 -> makeMove() == nullptr) player2 -> setMove(move2);

    Referee referee;
    Player* result = referee.refGame(player1,player2);
    
    // ===========================Let the game commence!============================================
    if (result != nullptr){
        // it shall return either a pointer to player1 or to player2
        if (result -> getName() == player1 -> getName()) std::cout << player1 -> getName() << " Wins." << std::endl;
        else std::cout << player2 -> getName() << " Wins." << std::endl;
    }
    else std::cout << "It's a Tie.\n";

    
    // Free all allocated resources/memory back to the heap
    delete move1;
    delete move2;
    delete player1;
    delete player2;
    return 0;
}