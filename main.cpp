// #include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Referee.h"


int main(int argc, char** argv){
    Human* human1 = new Human("Mei");
    // human1.setMove();
    Computer* computer = new Computer;

    Referee referee;
    Player* result = referee.refGame(human1,computer);
    // if (result -> getName() == human1.getName()){
    //     std::cout << human1.getName() << " Wins.\n";
    // }
    // else if(result -> getName() == computer.getName()){
    //     std::cout << computer.getName() << " Wins.\n";
    // }
    // else{
    //     std::cout << "It's a Tie.\n";
    // }
    if (result == nullptr){
        std::cout << "It's a Tie.\n";
    }
    else{ // it's a not tie 
        if (result -> getName() == human1->getName()) std::cout << human1 -> getName() << " Wins.\n";
        else std::cout << computer -> getName() << " Wins.\n";
    }
    delete human1;
    delete computer;


    return 0;
}
