#include "LinkedList.h"
#include <limits>

LinkedList::LinkedList(int* array, int len): listSize(len){
    if (len == 0) this -> head = nullptr; // create an empty linked list 
    else{
        this -> head = nullptr; 
        Node* newNode;
        for (int i = len-1; i>=0; i--){
            newNode = new Node(array[i], this -> head);
            this -> head = newNode;            
        }
    }
}
LinkedList::LinkedList(): LinkedList(nullptr, 0){
    
}

Node* LinkedList::traverseTo(unsigned int destinationPos){
    Node* curr = head;
    unsigned int i = 0;
    // int dest = destinationPos - 1;
    // std::cout << "Before dereferencing...\n";
    if (curr == nullptr) return nullptr;
    // curr is not a nullptr, or a non-empty list 
    while (curr -> getLink() != nullptr && i < destinationPos){
        curr = curr -> getLink();
        i++;
    }

    // std::cout << "After dereferencing...ok\n";
    // std::cout << "In traverse: \n";
    // std::cout << curr -> getData() << std::endl;
    // std::cin.ignore();

    return curr;
}

Node* LinkedList::getToFront(){return this -> head;}

Node* LinkedList::getToLast(){
    Node* curr_last = head;
    if (curr_last == nullptr) return nullptr;

    // not an empty list 
    while (curr_last ->getLink() != nullptr){
        curr_last = curr_last -> getLink();
    }
    return curr_last;
}


void LinkedList::push_front(int data){
    head = new Node(data, head);
}


void LinkedList::push_back(int data){
    Node* last = getToLast();
    if (last == nullptr){ // an empty list 
        head = new Node(data, nullptr);
    }// otherwise 
    else last -> setLink(new Node(data, nullptr));
}


void LinkedList::insertPosition(int pos, int newNum){
    // std::cout << "In insertPosition()" << std::endl;
    if (pos <= 1){ // push front 
       push_front(newNum);
    }

    else if (pos > 1 && pos <= listSize){
        int pos_arg = pos-2;
        // std::cout << "In 2nd else if" << std::endl;
        Node* prevNode = traverseTo(pos_arg);
        
        // std::cout << "failed at traverse to previous node" << std::endl;
        if (prevNode == nullptr){ // an empty list 
            // std::cout << "prevNode is a nullptr" << std::endl;
            // return;
            push_front(newNum); // or 
            // push_back(newNum); 
        }
        else{ // a non-empty list 
            Node* newNode = new Node(newNum, prevNode -> getLink());
            prevNode -> setLink(newNode);
        }
        
    }

    else{ // pos > size of the list 
        // std::cout << "in push back branch\n";
        push_back(newNum);
    }
}




bool LinkedList::deleteFront(){
    if (head == nullptr) return false; // empty list 
    Node* curr = head;
    head = head -> getLink();
    delete curr;
    return true;
}



bool LinkedList::deleteBack(){
    if (head == nullptr) return false; // empty list 
    Node* beforeLast = traverseTo(listSize-2);
    // std::cout << "before last data: " << beforeLast ->getData() << std::endl;
    Node* lastLink = beforeLast -> getLink();
    beforeLast -> setLink(nullptr);
    delete lastLink;
    return true;
}


bool LinkedList::deletePosition(int pos){
    // Remove node at position pos, 

    // if successful, return true
    // else, return false 
    int pos_arg = pos - 1;

    // used to be ||
    if (pos_arg < 0 && pos_arg > listSize-1) return false;
    else{
        Node* prevNodeToBeDeleted = traverseTo(pos_arg-1);
        Node* curr = prevNodeToBeDeleted -> getLink();
        prevNodeToBeDeleted -> setLink(curr -> getLink());
        curr -> setLink(nullptr);
        delete curr;
        
        return true;
    }




}

int LinkedList::get(int pos){
    if (head == nullptr) return std::numeric_limits<int>::max();
    if (pos-1 < 0 || pos-1 > listSize-1) return std::numeric_limits<int>::max();
    return traverseTo(pos-1) -> getData();
}

int LinkedList::search(int target){
    if (head == nullptr) return -1;
    
    // Node* curr = head;
    int x = 0;
    // while (curr -> getLink() != nullptr){
    //     if (curr -> getData() == target) break;
        
    //     x++;
    // }
    for (x = 0; x < listSize; x++){
        Node* curr = traverseTo(x);
        int d = curr -> getData();
        if (d == target) break;
        else continue;
    }
    
    if (x == listSize) return -1; // searched the entire list and target is nowhere to be found
    else return x + 1; // target is found somewhere 
    // return x+1;
}

// void LinkedList::printList(){
//     // std::cout << "In print list()" << std::endl;
    
//     std::cout << "[";
//     Node* curr = head;
//     int i = 0;
//     while (curr != nullptr){
//         if (i == listSize - 1) std::cout << curr -> getData();
//         else std::cout << curr -> getData() << " ";
//         i++;
//         curr = curr ->getLink();
//     }
//     std::cout << "]" << std::endl;
// }
void LinkedList::printList() {
    Node* curr = head;
    std::cout << "[";
    while (curr != nullptr) {
        std::cout << curr->getData();
        if (curr->getLink() != nullptr) {
            std::cout << " ";
        }
        curr = curr->getLink();
    }
    std::cout << "]" << std::endl;
}



LinkedList::~LinkedList(){
    // while the list is not empty 
    while (head != nullptr){
        Node* oldHead = head;
        head = head -> getLink();
        delete oldHead;
    }
} 