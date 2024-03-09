#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"



class Human: public Player{
    // private:
    public:
        Human(std::string name, Move* move);
        Human(std::string name);
        Human();        
        // void setMove(Move* move) override;
        Move* makeMove() override;
        std::string getName() override;
        ~Human();
};



#endif