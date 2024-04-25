#include "LinkedList.h"



LinkedList::LinkedList(){}

LinkedList::LinkedList(int* array, int len){
    array = new int[len];

}

void LinkedList::insertPosition(int pos, int newNum){}


bool LinkedList::deletePosition(int pos){
    return true;
}

int LinkedList::get(int pos){
    return 1;
}

int LinkedList::search(int target){
    return 1;
}

void LinkedList::printList(){
    std::cout << "[";


    std::cout << "]";
}




LinkedList::~LinkedList(){
    delete head;
} 