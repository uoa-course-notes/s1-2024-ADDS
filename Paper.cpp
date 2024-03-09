#include"Paper.h"

Paper::Paper(){
    this->name = "Paper";
    // winRelationship is a vector that stores a collection of moves that win against Paper
    this->winRelationship.push_back("Scissor");

    // loseRelationship is a vector that stores a collection of moves that lose against Paper
    this->loseRelationship.push_back("Rock");
}

Paper::~Paper(){}