#include "Human.h"

Human::Human(std::string name, Move* move)
    :Player(name, move){}

Human::Human(std::string name): Player(name){}

Human::Human()
    :Player("Human", nullptr){}

Move* Human::makeMove(){
    // std::cout << "Enter move: ";
    // std::string input;
    // create a move method such that 
    // if new moves are added into the game in the future, 
    // makeMove() method shouldn't need to be modified
    // this -> move = move;
    // return move;
    return Player::makeMove(); // this is not common but should still do the work
    // Human doesn't need to override Player's make move because they work exactly the same way
}

// void Human::setMove(char move){
//     std::cout << "Enter move: ";
//     std::cin >> move;
//     this -> move = move;
// }

std::string Human::getName(){
    return name;
}


Human::~Human(){}



