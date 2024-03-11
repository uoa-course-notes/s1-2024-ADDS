#ifndef MOVE_FACTORY_H
#define MOVE_FACTORY_H


// #include "Move.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Ninja.h"
#include "Zombie.h"
#include "Pirate.h"


class moveFactory{
    public:// a utility method
        static Move* createMove(const std::string& moveName);
};



#endif