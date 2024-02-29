#include "Human.h"

Human::Human(std::string name, char move)
    : Player(name, move)
{}

Human::Human(std::string name): Player(name){}
Human::Human()
    :Human("Human", '_'){}

char Human::makeMove(){
    std::cout << "Enter move: ";
    std::cin >> move;
    this -> move = move;
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



