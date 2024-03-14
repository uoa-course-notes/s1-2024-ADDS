#include <iostream>
#include <string>
#include "Reverser.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"

// #include <typeinfo>

// int numberTrucks(int numCrates, int loadSize){
//     // if the number of crates reaches the size of the load per (one) truck, return it 
//     // if (numCrates <= loadSize) return 1;
//     // else {
//     //     // if the number of crates is greater than the load size, 
//     //     // divide it into 2 
//     //     if (numCrates % 2 != 0){ // odd number of crates
//     //         return 2*(1 + numberTrucks((numCrates/2)+ 1, loadSize));     
//     //         // numCrates = (numCrates/2) + 1;
//     //     }
//     //     else { //even number of crates
//     //         return 2*(1 + numberTrucks(numCrates/2, loadSize));     
//     //     }
//     // }
//     if (numCrates <= loadSize) return 1;
//     else{
//     if (numCrates % 2 == 0) 
//         return numberTrucks(numCrates/2, loadSize) + numberTrucks(numCrates/2,  loadSize);
//     else 
//         return numberTrucks(numCrates/2, loadSize) + numberTrucks((numCrates/2) + 1, loadSize);
//     }
// }

// std::string reverseString(std::string characters){
//     if (characters == "") return "ERROR";
//     if (characters.size() == 1) return characters;
//     else return characters[characters.size()-1] + reverseString(characters.substr(0, characters.size()-1));
//     // return characters;
// }

int main(){ 
    // Reverser r;
    // int reversedNumber = r.reverseDigit(12345);
    // // reversedNumber should have the value of 54321
    // std::cout << reversedNumber << std::endl;

    // std::string reversedString = r.reverseString("Piseth");
    // // reversedString now should have the value of htesiP
    // std::cout << reversedString << std::endl;
    
    // int x = 11;
    // std::cout << "Break " << x << " into:" << std::endl;
    
    // if (x % 2 != 0){ // odd number
    //     std::cout << x/2 << ", " << (x/2)+1 << std::endl;
    // }
    // else std::cout << x/2 << ", " << x/2 <<  std::endl;

    // ==========================Problem 1=============================
    // int n1 = 1024;
    // int n2 = 5;
    // Truckloads T;
    // int trucks = T.numTrucks(n1, n2);
    // std::cout << "Number of trucks: " << trucks << std::endl;
    
    
    // ===========================Problem 2============================
    
    std::string s = "avalanche";
    int size = s.size();
    Reverser r;
    std::cout << r.reverseString(s) << std::endl;
    // std::cout << reverseString(s) << std::endl;
    
    // std::string sub = s.substr(0,size); // from 0 to size-1
    // std::cout << sub << std::endl;    
    
   

    

    return 0;
}