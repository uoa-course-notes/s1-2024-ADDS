#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
#include <cctype>
#include <cstddef>
#include <string>
#include <vector> 
#include <limits>
// Elements in the list are indexed from 1 to length 
class LinkedList{
    private:
        Node* head;
        int listSize;
    public:
        // A default constructor that creates an empty list
        LinkedList();
        // A constructor that creates a list from C-array of length len
        LinkedList(int* array, int len);
            
        // Traverse until position i
        Node* traverseTo(unsigned int destinationPos);
        
        Node* getToLast();

        Node* getToFront();

        // method to insert a new node containing the number newNum into the pos position
        void insertPosition(int pos, int newNum);   

        // Push the element into the front of the list 
        void push_front(int data);

        // Push the data into the back of the list 
        void push_back(int data);


        // A pos of 1 (or less) places a new node at the front of the list
        // A pos that exceeds the size of the list should add the node to the end of the list 
        
        // method to remove the node at position pos from the list and delete it,
        // if it successfully deletes the node, it should return true. If pos is out-of-bound, it should return false.
        bool deletePosition(int pos);

        // delete whatever element is on the front of the list 
        bool deleteFront();


        // delete whatever element is on the back of the list 
        bool deleteBack();


        // method that return pos's Node's data member variable .
        // If pos is out-of-bound, it should return std__numeric_limits<int> ::max().
        int get(int pos);

        // searches the list for the first occurence of target, in the list and returns the index of 
        // where target is. If target does not exist in the list, return -1
        int search(int target);

        // method that prints the data of all nodes in the list, separated by spaces and 
        // encapsulated by '[' and ']'. In the case of an empty list, it prints nothing. 
        void printList();

        // A destructor that deletes all nodes from the list
        ~LinkedList();

};



#endif