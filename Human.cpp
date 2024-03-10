#include "Human.h"

Human::Human(std::string name, Move* move)
    : Player(name, move)
{}

Human::Human(std::string name): Player(name){}

Human::Human()
    :Player("Human", nullptr){}

Move* Human::makeMove(){
    // std::cout << "Enter move: ";L
    
    // this -> move = move;
    return move;
    // std::cout << "Enter move: ";
    // std::cin >> move;
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



