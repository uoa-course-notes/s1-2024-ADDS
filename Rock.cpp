#include"Rock.h"

Rock::Rock(){
    this->name = "Rock";
    // winRelationship is a vector that stores a collection of moves that win against rock
    this->winRelationship.push_back("Scissor");
    this->winRelationship.push_back("Scissor");

    // loseRelationship is a vector that stores a collection of moves that lose against rock
    this->loseRelationship.push_back("Paper");
    this->loseRelationship.push_back("Scissor");

}

Rock::~Rock(){}