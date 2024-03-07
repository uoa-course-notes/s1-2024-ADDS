#include "Move.h"




std::string Move::getName(){
    return name;
}

int Move::compareMoves(Move* move) {
    for(unsigned int i = 0; i < this->winRelationship.size(); i++) if(this->winRelationship.at(i) == move->getName()) return 1; //win
    for(unsigned int i = 0; i < this->loseRelationship.size(); i++) if(this->loseRelationship.at(i) == move->getName()) return 2; // lose
    return 3; // tie
}
