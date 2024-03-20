#ifndef __STACK_H__
#define __STACK_H__


#include <iostream>
/**
 * @brief The Stack class implements the stack ADT
 * 

 @param value: int
 */

class Stack{
    private:
        int* S;       // A to-be dynamic array of integer
        int counter;  // This counter keeps track of the current element of the stack
        int capacity; // The maximum element of the stack
    public:
        Stack(int value);
        Stack();

        // Insert an element into the stack
        void push(int x);
        
        // Remove and return the top element of the stack
        int pop();

        // Print all elements from top to bottom
        // i.e., starting from the counter down to 0
        // In an array, it starts from the last elements back to zero.
        void print() const;

        // Return the top element without removing it
        int top() const;

        // Check if the stack is empty
        bool isEmpty();

        // Look for the current size of the stack
        int size() const;

        int* getStack();
        ~Stack();



};




#endif