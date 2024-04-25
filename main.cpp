
#include "Node.h"
#include "LinkedList.h"


std::vector<int> split_to_ints(std::string input, std::string valid){
    size_t startPos = 0;
    size_t endPos;
    size_t subStringLength;

    std::vector<int> result;
    do{
        endPos = input.find_first_not_of(valid, startPos);
        // if not found in string
        if (endPos == std::string::npos){
            subStringLength = input.length();
        }

        // otherwise
        else{
            subStringLength = endPos - startPos;
        }

        result.push_back(std::stoi(input.substr(startPos, subStringLength)));
        startPos = input.find_first_not_of(valid, endPos);
    } while(endPos != std::string::npos);

    return result;
}





int main(int argc, char** argv){
    // Take in user inputs - this code addumes for a valid input
    std::string user_input;
    std::getline(std::cin, user_input);

    // cut out the numbers from user_input & place into vector of ints 
    std::string numeric_characters = "-0123456789";
    std::vector<int> numeric_inputs = split_to_ints(user_input, numeric_characters);

    // copy all  (but the last 2) digits from vector into a c-array (to be passed into LinkedList constructor)
    int array_size = numeric_inputs.size() - 2;

    int* input_array = new int[array_size];
    for (unsigned int i = 0; i< (numeric_inputs.size()-2); i++){
        input_array[i] = numeric_inputs[i];
    }

    // then, copy the last 2 digits from user_input (i.e., the parameters) into a prameter array 
    int param_array[2] = {
        numeric_inputs.at(numeric_inputs.size() - 2),
        numeric_inputs.at(numeric_inputs.size() - 1)
    };

    // Finally copy the letter code into a new variable 
    std::string commandCode;
    for (unsigned int i = 0; i<user_input.length(); i++){
        if (std::isalpha(user_input[i])){
            commandCode.push_back(user_input[i]);
        }
    }

    // create list based on input data & array size 
    LinkedList submissionList(input_array, array_size);

    // run function on the list depending on the letter code, using the parameter 
    if (commandCode =="I"){
        submissionList.insertPosition(param_array[0],param_array[1]);
    }
    else if (commandCode=="D"){
        if (!submissionList.deletePosition(param_array[0])){
            std::cout << "ERROR";
        }
    }
    else if (commandCode == "S"){
        int got = submissionList.deletePosition(param_array[0]);
        if (got == -1){std::cout << "ERROR";}
        else std::cout << got << " ";
    }
    else if(commandCode =="G"){
        int got = submissionList.deletePosition(param_array[0]);
        if (got == std::numeric_limits<int>::max()){std::cout << "ERROR";}
        else std::cout << got << " ";
    }

    else{
        std::cout << "invalid command" << std::endl;
        return 0;
    }
    submissionList.printList();




    return 0;
}

/*

After the elements of the list, the input consists of a string, denoting a function, followed by its parameters. The string is one of these:

I standing for insertPosition
D standing for deletePosition
S standing for search
G standing for get
For each of the following inputs passed into main, the program's output should be as follows.

Sample input: 5 2 7 10 I 3 9
expected output: [5 2 9 7 10]

Sample input: 3 4 2 1 D 3 0
expected output: [3 4 1]

Sample input: 45 20 2 10 G 3 0
expected output: 2 [45 20 2 10]

*/