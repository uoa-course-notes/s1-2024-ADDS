#ifndef BIG_NUM_CAL_H
#define BIG_NUM_CAL_H
#include <list>
#include <string>

/*
Task: Create a very simplified big number calculator.
Assumptions: All inputs are positive integers. 
- A number should be at least 1 digit long
- A number should not have trailing 0s at the end of one's result 

*/

class BigNumCalc{
    public:
        BigNumCalc();
        BigNumCalc(int x);
        ~BigNumCalc();
        
        // Creates a list representing the provided string 
        // Input: "12345"
        // > [1,2,3,4,5]
        std::list<int> buildBigNum(std::string numString);


        // Add num1 and num2
        std::list<int> add(std::list<int> num1, std::list<int> num2);
        

        // Subtract num2 from num1
        std::list<int> sub(std::list<int> num1, std::list<int> num2);
            
        // Multiply num1 and num2
        std::list<int> mul(std::list<int> num1, std::list<int> num2);
        // For simplicity, assume that num2 will be only one digit long. 
        




};



#endif 