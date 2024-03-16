#include <iostream>
#include <string>
// #include <string>
#include "Reverser.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include <cmath>


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

int reverse_digit(int n){   
    if (n == 0) return 0;
    int lastDigit = n % 10;
    // int remainingNumber = n / 10;
    // std::cout << lastDigit << std::endl;
    // int rev_remaining = lastDigit*10 + reverse_digit(remainingNumber);       
    return (reverse_digit(n/10) * 10) + lastDigit;
}


int reverseNumber(int number) {
    // Base case: when the number becomes zero, return
    if (number == 0) {
        return 0;
    }
    
    // Extract the last digit of the number
    int lastDigit = number % 10;
    // Remove the last digit from the number
    int remainingNumber = number / 10;
    // Recur with the remaining digits
    int reversedRemaining = reverseNumber(remainingNumber);
    // Append the last digit to the reversed remaining number
    int reversedNumber = reversedRemaining * 10 + lastDigit;
    return reversedNumber;

}

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
    
    // std::string s = "avalanche";
    // int size = s.size();
    // Reverser r;
    // std::cout << r.reverseString(s) << std::endl;
    
    // ===========================Problem 3============================
    std::string s = "123456";
    int t = std::stoi(s);

    int x = 1482;
    // std::cout << x/10 << std::endl; // find the quotient
    // std::cout << t+1 << std::endl;
    // std::cout << x % 1 << std::endl; 0
    // std::cout << x % 10 << std::endl;  2
    // std::cout << x % 100 << std::endl; 82
    // std::cout << x % 1000 << std::endl; 482
    // std::cout << x % 10000 << std::endl; 1482
    // std::cout << x % 100000 << std::endl; 1482

    int a = 10;
    int k = x;
    std::cout << x << std::endl;
    int reversed = reverseNumber(x);
    std::cout << reversed << std::endl;
    
    
    // while(true){
    //     std::cout << x % a << std::endl;
    //     if (x % a == k) break;
    //     a = a*10;
    // }
    // int rev_num = 0;
    // int rem = 0;
    // int quotient = 0;
    // while (x != 0){
    //     rem = x % 10;
    //     rev_num = rev_num * 10 + rem;
    //     x = x / 10;
    // }
    // std::cout << rev_num << std::endl;
    
    
    
    return 0;
}