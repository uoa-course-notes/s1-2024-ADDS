#include "Ninja.h"


Ninja::Ninja(){
    this->name = "Ninja";
    // winRelationship is a vector that stores a collection of moves that win against Ninja
    this->winRelationship.push_back("Monkey");
    this->winRelationship.push_back("Robot");

    // loseRelationship is a vector that stores a collection of moves that lose against Ninja
    this->loseRelationship.push_back("Pirate");
    this->loseRelationship.push_back("Zombie");
}

Ninja::~Ninja(){}