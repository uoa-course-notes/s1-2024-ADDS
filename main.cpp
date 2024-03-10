#include <iostream>
#include "Reverser.h"
#include "Truckloads.h"
// #include "gwindow.h"

void iterative_reverse(int& digits){
    digits = digits + 1;
    // return digits;
    
}



int main(){ 
    // Reverser r;
    // int reversedNumber = r.reverseDigit(12345);
    // // reversedNumber should have the value of 54321
    // std::cout << reversedNumber << std::endl;

    // std::string reversedString = r.reverseString("Piseth");
    // // reversedString now should have the value of htesiP
    // std::cout << reversedString << std::endl;
    
    int x = 10;
    // iterative_reverse(x);
    std::cout << x << std::endl;
    
    const int y = 0;
    // y = 10;
    int& a = x;

    int& b = x;

    a = y;
    std::cout << a << std::endl;

    return 0;
}