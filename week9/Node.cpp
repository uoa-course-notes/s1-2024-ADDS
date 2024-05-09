#include "Node.h"


Node::Node(int data, Node* leftChild, Node* rightChild)
            : data(data), leftChild(leftChild), rightChild(rightChild){}

Node::Node(int data): Node(data, nullptr, nullptr){}

Node::Node(): Node(0,nullptr,nullptr){}

int Node::getData(){return data;}
Node* Node::getLeftChild(){return leftChild;}
Node* Node::getRightChild(){return rightChild;}


void Node::setData(int data){this -> data = data;}
void Node::setLeftChild(Node* leftChild){this -> leftChild = leftChild;}
void Node::setRightChild(Node* rightChild){this -> rightChild = rightChild;}





Node::~Node(){}