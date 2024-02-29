#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player{
    protected:
        char move;
        std::string name;
    public:
        Player(std::string name, char move);
        Player(std::string name);
        Player();
        virtual char makeMove() = 0;
        virtual std::string getName() = 0;
        virtual ~Player();



};




#endif