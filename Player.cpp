#include "Player.h"
#include "MoveFactory.h"

Player::Player(std::string name, Move* move)
    : name(name), move(move){}


Player::Player(std::string name): name(name), move(nullptr){}

Player::Player():
    Player("", nullptr){}

Move* Player::makeMove(){
    std::cout << "-------------" << this -> name << "'s turn----------------" << std::endl; 
    std::cout  << "Enter move: ";
    std::string input;
    std::cin >> input;
    
    move = moveFactory::createMove(input);
    // while (m != nullptr){        

    // }
    if (move == nullptr){
        // when move is a nullptr or an invalid one
        while (move == nullptr){
        // std::cout << "Invalid move." << std::endl;
            std::cout << "Invalid Move! Enter a valid move: ";
            std::cin >> input;
            move = moveFactory::createMove(input);
        }
    }
    // if move is not a nullptr
    return move;
}

// void Player::setMove(Move* move){
//     this -> move = move;
// }



Player::~Player(){delete move;}