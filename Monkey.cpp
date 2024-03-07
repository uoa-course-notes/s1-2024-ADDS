#include"Monkey.h"

Monkey::Monkey(){
    this->name = "Monkey";
    // winRelationship is a vector that stores a collection of moves that win against monkey
    this->winRelationship.push_back("Pirate");
    this->winRelationship.push_back("Zombie");

    // loseRelationship is a vector that stores a collection of moves that lose against monkey
    this->loseRelationship.push_back("Ninja");
    this->loseRelationship.push_back("Robot");

}

Monkey::~Monkey(){}