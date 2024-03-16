#include "Reverser.h"
// #include <string>


// int Reverser::reverseDigit(int value){
//     std::string x = std::to_string(value);
//     if (value < 0) return -1;
//     else{
//         return 1;
//     }
//     return value;
// }

int Reverser::reverseDigit(int value){
    int reversed = 0;
    int lastDigit = 0;
    while (value != 0){
        lastDigit = value % 10;
        reversed = reversed * 10 + lastDigit; 
        value = value / 10;
    }
    return reversed;
}

std::string Reverser::reverseString(std::string characters){
    if (characters == "") return "ERROR";
    if (characters.size() == 1) return characters;
    else return characters[characters.size()-1] + reverseString(characters.substr(0, characters.size()-1));
    // return characters;
}