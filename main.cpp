// Include our 'main' entities
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Referee.h"

// Include the classic RSP
// #include "Rock.h"
// #include "Scissor.h"
// #include "Paper.h"

// // Include additional moves
// #include "Ninja.h"
// #include "Robot.h"
// #include "Pirate.h"
// #include "Zombie.h"
// #include "Monkey.h"

// void game(){

// }


int main(int argc, char** argv){
    Player* player1 = new Human("John");
    // if (player1 -> makeMove() == nullptr) player1 -> setMove(move1);
    // Move* move1 = player1 -> makeMove();

    // Player* player2 = new Human("Seth");
    Player* player2 = new Computer();
    // Move* move2 = player2 -> makeMove();

    // if (player2 -> makeMove() == nullptr) player2 -> setMove(move2);

    Referee referee;
    Player* result = referee.refGame(player1,player2);
    
    // ===========================Let the game commence!============================================
    /*std::cout << "============Welcome to Rock-Paper-Scissor-Monkey-Robot-Zombie-Ninja-Pirate Game=================" << std::endl;
    int numPlayers = 0;
    std::cout << "Enter the number of players:";
    std::cin >> numPlayers;

    if (numPlayers >= 2){
        Player** players = new Player*[numPlayers];

    }
    else std::cout << "There should at least be 2 players within the game." << std::endl;
*/
    if (result != nullptr){
        // it shall return either a pointer to player1 or to player2
        if (result -> getName() == player1 -> getName()) std::cout << player1 -> getName() << " Wins." << std::endl;
        else std::cout << player2 -> getName() << " Wins." << std::endl;
    }
    else std::cout << "It's a Tie.\n";


    
    // Free all allocated resources/memory back to the heap
    // delete move1;
    // delete move2;
    delete player1;
    delete player2;
    return 0;
}