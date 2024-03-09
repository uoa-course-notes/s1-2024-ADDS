#include "Zombie.h"


Zombie::Zombie(){
    this -> name = "Zombie";
    // winRelationship is a vector that stores a collection of moves that win against Zombie
    this->winRelationship.push_back("Robot");
    this->winRelationship.push_back("Ninja");

    // loseRelationship is a vector that stores a collection of moves that lose against Zombie
    this->loseRelationship.push_back("Pirate");
    this->loseRelationship.push_back("Monkey");
}


Zombie::~Zombie(){}