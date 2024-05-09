#pragma once 

#include "Node.h"
#include <vector>



class Tree{
    private:
        
        Node* root;
    public:
        Tree();

        void insert(int value);

        void remove(int target);

        bool search(int key);


        ~Tree();

};