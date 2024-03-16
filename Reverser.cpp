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

// int helper(int n, int acc = 0){
//     if (n < 0) return -1;
//     int rev = 0;
//     int last_digit = 0;
//     if (n < 10) return n;
//     else{
//         last_digit = n % 10;
        
//     }
// }
int helper(int value, int rev = 0){
    // if (value < 0) return -1;
    // int reversed = 0;
    // int lastDigit = 0;
    // while (value != 0){
    //     lastDigit = value % 10;
    //     reversed = reversed * 10 + lastDigit; 
    //     value = value / 10;
    // }
    // return helper(value);
    if (value < 0) return -1;
    else{
        if (value < 10) return rev * 10 + value; // 1
        int last_digit = value % 10;
        return helper(value/10, rev*10 + last_digit);
    }
}
int Reverser::reverseDigit(int value){
    return helper(value);
}




std::string Reverser::reverseString(std::string characters){
    if (characters == "") return "ERROR";
    if (characters.size() == 1) return characters;
    else return characters[characters.size()-1] + reverseString(characters.substr(0, characters.size()-1));
    // return characters;
}