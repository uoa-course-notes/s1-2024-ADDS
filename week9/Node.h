#pragma once 
#include <iostream>



class Node{
    private:
        int data;
        Node* leftChild;
        Node* rightChild;
    public:
       Node(int data, Node* leftChild, Node* rightChild);
       Node();
       Node(int data);


       int getData();
       Node* getLeftChild();
       Node* getRightChild();

       void setData(int data);
       void setLeftChild(Node* leftChild);
       void setRightChild(Node* rightChild);

       ~Node();
};