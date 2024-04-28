// #include "LinkedList.h"
#include "BigNumCalc.h"


// std::vector<int> split_to_ints(std::string input, std::string valid){
//     size_t startPos = 0;
//     size_t endPos;
//     size_t subStringLength;
//     std::vector<int> result;
    
//     do{
//         endPos = input.find_first_not_of(valid, startPos);
//         // if not found in string
//         if (endPos == std::string::npos){
//             subStringLength = input.length();
//         }

//         // otherwise
//         else{
//             subStringLength = endPos - startPos;
//         }

//         result.push_back(std::stoi(input.substr(startPos, subStringLength)));
//         startPos = input.find_first_of(valid, endPos);
//     } while(endPos != std::string::npos);

//     return result;
// }



// // void printV(std::vector<int> V){
// //     std::cout << "<";
// //     for (int i=0; i<V.size(); i++){
// //         if (i == V.size() - 1) std::cout << V[i];
// //         else std::cout << V[i] << ",";
// //     }
// //     std::cout << ">" << std::endl;
// // }


// void printA(int* array, int n){
//     std::cout << "<";
//     for(int i=0; i<n; i++){
//         if (i == n-1) std::cout << array[i];
//         else std::cout << array[i] << ",";
//     }
//     std::cout << ">" << std::endl;
// }


int main(void){
        BigNumCalc calculator;
        std::string input1 = "115364565";
        std::string input2 = "146536475";
        

        // std::list<int> LA = big.buildBigNum(input1);
        // std::list<int> LB = big.buildBigNum(input2);

        // std::list<int> add_res = big.add(LA, LB);
        // std::list<int> sub_res = big.sub(LA, LB);
        // std::list<int> mul_res = big.mul(LA, LB);

// Test addition
    std::list<int> num1 = calculator.buildBigNum("1234567890");
    std::list<int> num2 = calculator.buildBigNum("9876543210");
    std::list<int> sum = calculator.add(num1, num2);
    for (int digit : sum) {
        std::cout << digit;
    }
    std::cout << std::endl;

    // Test subtraction
    num1 = calculator.buildBigNum("9876543210");
    num2 = calculator.buildBigNum("1234567890");
    std::list<int> diff = calculator.sub(num1, num2);
    for (int digit : diff) {
        std::cout << digit;
    }
    std::cout << std::endl;


//     // Take in user inputs - this code addumes for a valid input
//     std::string user_input;
//     std::getline(std::cin, user_input);

//     // cut out the numbers from user_input & place into vector of ints 
//     std::string numeric_characters = "-0123456789";

//     // ===== Example: 
//     // Input: 5 2 7 10 I 3 9
//     // numeric_inputs = <5,2,7,10,3,9>, i.e.,'I' had been removed.
//     std::vector<int> numeric_inputs = split_to_ints(user_input, numeric_characters);
    
//     // printV(numeric_inputs); Indeed, it works as expected. 
    
    
//     // copy all  (but the last 2) digits from vector into a c-array (to be passed into LinkedList constructor)
//     int array_size = numeric_inputs.size() - 2; // the last two digits are parameters into different Linked List's class methods. 
//     // ==== input_array = <5,2,7,10>
//     int* input_array = new int[array_size];
//     for (int i = 0; i< array_size; i++){
//         input_array[i] = numeric_inputs[i];
//     }
//     // printA(input_array, array_size); works as expected 
    
//     // ==== 3 and 9 in our case
//     // then, copy the last 2 digits from user_input (i.e., the parameters) into a prameter array 
//     int param_array[2] = {
//         numeric_inputs.at(numeric_inputs.size() - 2),
//         numeric_inputs.at(numeric_inputs.size() - 1)
//     };
//     // printA(param_array, 2);

//     // Finally copy the letter code into a new variable 
//     std::string commandCode;
//     for (unsigned int i = 0; i<user_input.length(); i++){
//         if (std::isalpha(user_input[i])){
//             commandCode.push_back(user_input[i]);
//     // Did commandCode, a data of type string just use a push_back operation?!, 
//     // That's new. But with abstraction, anything is possible these days. 
//         }
//     }
//     // std::cout << commandCode << std::endl; works as expected 


//     // create list based on input data & array size 
//     // submissionList.printList();
//     LinkedList submissionList(input_array, array_size);
    
//     // // run function on the list depending on the letter code, using the parameter 
//     if (commandCode =="I"){
//         submissionList.insertPosition(param_array[0],param_array[1]);
//     }
//     else if (commandCode=="D"){
//         if (!submissionList.deletePosition(param_array[0])){
//             std::cout << "ERROR";
//         }
//     }
//     else if (commandCode == "S"){
//         int got = submissionList.deletePosition(param_array[0]);
//         if (got == -1){std::cout << "ERROR";}
//         else std::cout << got << " ";
//     }
//     else if(commandCode =="G"){
//         int got = submissionList.get(param_array[0]);
//         if (got == std::numeric_limits<int>::max()){std::cout << "ERROR";}
//         else std::cout << got << " ";
//     }
//     else{
//         std::cout << "invalid command" << std::endl;
//         return 0;
//     }
//     submissionList.printList();




    return 0;
}

// /*

// After the elements of the list, the input consists of a string, denoting a function, followed by its parameters. The string is one of these:

// I standing for insertPosition
// D standing for deletePosition
// S standing for search
// G standing for get
// For each of the following inputs passed into main, the program's output should be as follows.

// Sample input: 5 2 7 10 I 3 9
// expected output: [5 2 9 7 10]

// Sample input: 3 4 2 1 D 3 0
// expected output: [3 4 1]

// Sample input: 45 20 2 10 G 3 0
// expected output: 2 [45 20 2 10]

// */