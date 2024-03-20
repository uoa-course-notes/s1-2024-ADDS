#include "Stack.h"

Stack::Stack(int val){
    counter = 0; // counter points to the current element of the stack
    
    // check if the user decides to push more than counter 10
    // elements into the stack, then 
    capacity = 10;
    S = new int[10]; // initialize an array of length 10
    // we will work on creating different cases.
    *(S+counter) = val;
    
    // there's an issue with adding an increment below
    // Suppose a user uses the same constructor again and again, then
    //  
    counter++;
}


Stack::Stack(): Stack(0){}




void Stack::print()const {
    for (int i=counter; i>=0; i--){
        std::cout << i+1 << ".\t"<< S[i] 
                  << std::endl;
    }
}

void Stack::push(int x){
    S[++counter] = x; 
}

int Stack::pop(){
    if (isEmpty() == true) return 0;
    else return S[counter--];
    // Return the "popped" element
    // In other words, return the content at counter and then 
    // decrement counter ==> ignoring or popping in the process
}

int Stack::top() const{
    return S[counter];
}




int Stack::size() const{
    return counter;
}


bool Stack::isEmpty(){
    return counter == 0;
}


int* Stack::getStack(){
    return S;
}


Stack::~Stack(){
    delete[] S;
}