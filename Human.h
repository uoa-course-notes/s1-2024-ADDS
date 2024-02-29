#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"



class Human: public Player{
    // private:
    public:
        Human(std::string name, char move);
        Human(std::string name);
        Human();        
        void setMove(char move);
        char makeMove() override;
        std::string getName() override;
        ~Human();
};



#endif