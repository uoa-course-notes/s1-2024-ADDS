#include "Node.h"

Node::Node(int data){
    this -> lst = nullptr;
    this -> rst = nullptr;
    this -> data = data;
}


Node::Node():Node(0){}

void Node::setData(int data){this -> data = data;}
int Node::getData(){return this -> data;}

void Node::setLST(Node* lst){this -> lst = lst;}
Node* Node::getLST(){return this -> lst;}

void Node::setRST(Node* rst){this -> rst = rst;}
Node* Node::getRST(){return this -> rst;}



Node::~Node(){
    // delete node;
}