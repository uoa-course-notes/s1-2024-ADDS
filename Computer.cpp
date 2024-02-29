#include "Computer.h"

Computer::Computer(): Player("Computer", 'R'){}

std::string Computer::getName(){return name;}
char Computer::makeMove(){return move;}

Computer::~Computer(){}

