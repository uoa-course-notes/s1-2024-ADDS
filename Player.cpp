#include "Player.h"

Player::Player(std::string name, char move)
    : name(name), move(move){}


Player::Player(std::string name): name(name){}

Player::Player():
    Player("", '_'){}


Player::~Player(){}


