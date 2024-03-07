#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"

class Computer: public Player{
    public:
        Computer(std::string name, char move);
        Computer();
        Move* makeMove() override;
        std::string getName() override;
        ~Computer();
        


};




#endif