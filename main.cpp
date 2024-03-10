#include <iostream>
#include "Reverser.h"
#include "Truckloads.h"


int main(){ 
    Reverser r;
    int reversedNumber = r.reverseDigit(12345);
    // reversedNumber should have the value of 54321
    std::cout << reversedNumber << std::endl;

    std::string reversedString = r.reverseString("Piseth");
    // reversedString now should have the value of htesiP
    std::cout << reversedString << std::endl;
    return 0;
}