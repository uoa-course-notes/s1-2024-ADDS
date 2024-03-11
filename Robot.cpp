#include "Robot.h"


Robot::Robot(){
    this -> name = "Robot";
    // winRelationship is a vector that stores a collection of moves that win against Robot
    this->winRelationship.push_back("Monkey");
    this->winRelationship.push_back("Pirate");

    // loseRelationship is a vector that stores a collection of moves that lose against Robot
    this->loseRelationship.push_back("Ninja");
    this->loseRelationship.push_back("Zombie");
}


Robot::~Robot(){}