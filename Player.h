#ifndef PLAYER_H
#define PLAYER_H

#include "MoveFactory.h"


class Player{
    protected:
        std::string name; // name of the player
        Move* move;       // the player's move
    public:
        Player(std::string name, Move* move);
        Player(std::string name);

        Player();
        virtual std::string getName() = 0;
        virtual Move* makeMove();
        // virtual void setMove(Move* move);
        virtual ~Player() = 0;

};






#endif