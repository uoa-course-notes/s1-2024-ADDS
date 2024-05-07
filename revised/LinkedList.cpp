#include "LinkedList.h"


LinkedList::LinkedList(int* data, int length){
    if (length == 0) this -> head = nullptr;
    else{
        // list is not set to be empty
        // list contains at least one element
        this -> head = nullptr;

        for (int i=length-1; i>= 0; i--){
            Node* node = new Node(data[i], this -> head);
            head = node -> getLink();
        }
    }
}

// empty list 
LinkedList::LinkedList(): LinkedList({}, 0){}

// If the list is supposed to start s = 1, then pass s-1 into this function 
Node* LinkedList::traverseTo(unsigned int destinationPos){
    Node* curr = head;
    int i = 0;
    // The list is empty and searching it is not viable.
    if (curr == nullptr) return nullptr;
    
    while (curr -> getLink() != nullptr && i < destinationPos){
        curr = curr -> getLink();
        i++;
    }
    // after this while loop, i should either be at the destination position 
    // or curr = nullptr which is at the last node 
    return curr;
}











LinkedList::~LinkedList(){
    Node* oldHead;
    while (head != nullptr){
        oldHead = head;
        head = head -> getLink();
        delete oldHead;
    }    
    // head should be a nullptr at this point and all the nodes
    // have been deleted
    oldHead = nullptr;

    // oldHead is set to be a nullptr to avoid dangling pointer
    // In our case, that need not be done but 
    // is done so in the name of best practice. 



}