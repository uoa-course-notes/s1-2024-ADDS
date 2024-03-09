#include "Computer.h"

Computer::Computer(std::string name, Move* move): Player(name, move){}

Computer::Computer(): Computer("Computer", nullptr){}

std::string Computer::getName(){return name;}
Move* Computer::makeMove(){return move;}

Computer::~Computer(){}

