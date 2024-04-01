#include "Sort.h"
#include <exception>
#include <stdexcept>

// template <typename T>
void print_value(char** A, int num){
    // there are "num" number of chracter
    for (int i=0; i<num; i++){
        // try{
        if (A[i] != nullptr){
            for (int j=0; A[i][j] != '\0'; j++)
            {
                    std::cout << A[i][j];
            }
            std::cout << std::endl;
        }
        else {
            // throw std::exception();
            throw std::runtime_error("Error -- trying to dereference nullptr");
        }
        // }
        // }catch(std::exception& ex){
        //     std::cout << "Dereferencing nullptr caught" << std::endl;
        //     // std::cout << "A nullptr has been caught" << std::endl;
        //     return;
        // }
        
    }
    std::cout << std::endl;
    
}



int main(int argc, char** argv){
    // std::cout << "How many command line arguments were there? " << argc << std::endl ;
    // std::cout << "And what are they? " << std::endl;
    // int i = 0;
    // // std::string* A[10] = {};
    // std::string x = "";
    // print_value(argv, argc);
    // std::cout << "Enter a string: ";
    // while (std::cin >> x){
    //     std::cout << "Enter a string: ";
    //     // A[i++] = x;

    //     // argv
    // }
    // char ** A = new char*[10];
    // char* a1 = "hello";
    // char* a2 = (char*) "hello1";
    // char* a3 = (char*) "hello2";
    // char* a4 = (char*) "hello3";
    // // std::cout << a1 << std::endl;
    // A[0] = a1;
    // A[1] = a2;
    // A[2] = a3;
    // A[3] = a3;
    // A[4] = a4;
    // print_value(A,10);
    std::vector<int> list;
    int x = 0;
    while (std::cin >> x){
        list.push_back(x);
    }

    
    int key = 1;

    

}
