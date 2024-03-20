
#include "Stack.h"


void printDetails(int* X, int n){
    for(int i=0; i<n; i++){
        std::cout << X[i] << std::endl;
    }
}


int main(int argc, char** argv){
    std::cout << "---------------------Welcome to the stack ADT-----------------\n";
    std::cout << "Give an operation (1-4):\n"
              << "1. Print elements \n"
              << "2. Get size\n"
              << "3. Pop a certain element\n"
              << "4. Push a certain element\n"
              << "----------------------------------------------------------------\n";
    
    Stack s(13);
    int* X = s.getStack();
    // push some elements into our stack
    s.push(4);
    s.push(100);
    s.push(123);
    s.push(90);
    s.push(31);
    s.push(20);
    s.push(210);
    s.push(1210);
    s.push(21);

    // counter is now at the 10th element...
    // Inserting one more element shall introduce a run-time segmentation fault
    // Here goes
    s.push(1202);
    s.print();
    std::cout << "Size: " << s.size() << std::endl;
    int a = s.size();
    s.push(10000);
    s.push(10000);
    s.push(10000);

    std::cout << "Size: " << s.size() << std::endl;
    std::cout << "Test stack: " << 
         X[0] << std::endl;
       
    printDetails(X, a);    


    return 0;
}
