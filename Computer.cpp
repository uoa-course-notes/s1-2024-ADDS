#include "Computer.h"
#include "MoveFactory.h"

Computer::Computer(std::string name, Move* move): 
    Player(name, move){}

Computer::Computer(std::string name): Player(name){}


Computer::Computer(): Player("Computer", nullptr){}



std::string Computer::getName(){return name;}
Move* Computer::makeMove(){
    // std::cout << "Computer's made its move (which is always Rock btw)" << std::endl;
    return moveFactory::createMove("Rock");
}

Computer::~Computer(){}

