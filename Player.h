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
        // Player(std::string name, char move);
        // Player(std::string name);

        // Player();
        virtual std::string getName();
        virtual Move* makeMove();
        virtual ~Player() = 0;



};




#endif