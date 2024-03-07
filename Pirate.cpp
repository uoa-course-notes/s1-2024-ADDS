#include "Pirate.h"

Pirate::Pirate(){
    this -> name = "Pirate";
    // winRelationship is a vector that stores a collection of moves that win against rock
    this->winRelationship.push_back("Ninja");
    this->winRelationship.push_back("Zombie");

    // loseRelationship is a vector that stores a collection of moves that lose against rock
    this->loseRelationship.push_back("Robot");
    this->loseRelationship.push_back("Monkey");
}


Pirate::~Pirate(){}