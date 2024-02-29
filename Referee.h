#ifndef REFEREE_H
#define REFEREE_H
#include "Player.h"


class Referee{
    public:
        // Constructor
        Referee();
        // Returns the reference to the winning player
        Player* refGame(Player* player1, Player* player2);


};



#endif