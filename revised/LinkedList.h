#pragma once 


#include "Node.h"

class LinkedList{
    private:
        Node* head;
        int listSize;
    public:
        LinkedList(int* data, int length); // create a list of data, with size length  
        LinkedList(); // create an empty list


        // =================Traverse to the i-th position==========================
        Node* traverseTo(unsigned int destinationPos);
        Node* getToLast();
        Node* getToFront();
        
        
        // ==========================INSERT============
        void insertAt(int pos, int newNum);
        void push_back(int newNum);
        void push_front(int newNum);
        

        // ======================DELETE ==================
        bool deleteAt(int pos);
        bool deleteFront();
        bool deleteBack();


        // =============ACCESS/INDEXING=======================
        int get(int pos);
        

        // SEARCHING 
        int search(int target);


        // PRINTING
        void printList();
        




        ~LinkedList();
        


};