#include "Computer.h"

Computer::Computer(): Player("Computer", 'R'){}

std::string Computer::getName(){return name;}
Move* Computer::makeMove(){return move;}

Computer::~Computer(){}

