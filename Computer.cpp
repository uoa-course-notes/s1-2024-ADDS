#include "Computer.h"

Computer::Computer(std::string name, Move* move): 
    Player(name, move){}

Computer::Computer(std::string name): Player(name){}


Computer::Computer(): Player("Computer", nullptr){}



std::string Computer::getName(){return name;}
Move* Computer::makeMove(){return new Rock();}

Computer::~Computer(){}

