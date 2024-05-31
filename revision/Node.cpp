#include "Node.h"


Node::Node(int data, Node* link){
    this -> data = data;
    this -> link = link;
}


Node::Node():Node(0, nullptr){}



int Node::getData(){return data;}
void Node::setData(int data){this ->data = data;}


Node* Node::getLink(){return link;}
void Node::setLink(Node* link){this -> link = link;}



Node::~Node(){}


