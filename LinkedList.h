#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"


// Elements in the list are indexed from 1 to length 
class LinkedList{
    private:
        Node* head;
    public:
        // A default constructor that creates an empty list
        LinkedList();
        // A constructor that creates a list from C-array of length len
        LinkedList(int* array, int len);

        // method to insert a new node containing the number newNum into the pos position
        void insertPosition(int pos, int newNum);        

        // A pos of 1 (or less) places a new node at the front of the list
        // A pos that exceeds the size of the list should add the node to the end of the list 

        // method to remove the node at position pos from the list and delete it,
        // if it successfully deletes the node, it should return true. If pos is out-of-bound, it should return false.
        bool deletePosition(int pos);

        // method that return pos's Node's data member variable .
        // If pos is out-of-bound, it should return std__numeric_limits<int> ::max().
        int getPos(int pos);

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