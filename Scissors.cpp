#include"Scissors.h"

Scissors::Scissors(){
    this->name = "Scissor";
    // winRelationship is a vector that stores a collection of moves that win against Scissor
    this->winRelationship.push_back("Rock");

    // loseRelationship is a vector that stores a collection of moves that lose against Scissor
    this->loseRelationship.push_back("Paper");
}

Scissors::~Scissors(){}