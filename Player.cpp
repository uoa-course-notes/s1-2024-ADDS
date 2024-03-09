#include "Player.h"

Player::Player(std::string name, Move* move)
    : name(name), move(move){}


Player::Player(std::string name): name(name), move(nullptr){}

Player::Player():
    Player("", nullptr){}

Move* Player::makeMove(){return move;}

// void Player::setMove(Move* move){
//     this -> move = move;
// }



Player::~Player(){}