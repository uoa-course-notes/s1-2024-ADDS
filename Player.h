#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

#include "Move.h"

class Player{
    protected:
        Move* move;
        std::string name;
    public:
        Player(std::string name, char move);
        Player(std::string name);

        Player();
        virtual std::string getName() = 0;
        virtual Move* makeMove() = 0;
        virtual ~Player() = 0;



};




#endif