#include "Pirate.h"

Pirate::Pirate(){
    this -> name = "Pirate";
    // winRelationship is a vector that stores a collection of moves that win against Pirate
    this->winRelationship.push_back("Ninja");
    this->winRelationship.push_back("Zombie");

    // loseRelationship is a vector that stores a collection of moves that lose against Pirate
    this->loseRelationship.push_back("Robot");
    this->loseRelationship.push_back("Monkey");
}


Pirate::~Pirate(){}