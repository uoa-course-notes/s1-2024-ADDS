#include "Reverser.h"


int Reverser::reverseDigit(int value){
    
    if (value < 0) return -1;
    
    return value;
}



std::string Reverser::reverseString(std::string characters){
    if (characters == "") return "ERROR";
    if (characters.size() == 1) return characters;
    else return characters[characters.size()-1] + reverseString(characters.substr(0, characters.size()-1));
    // return characters;
}