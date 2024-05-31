#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"


class Queue{
    private:
        Node* head;
        Node* tail;
        Node* dummyTail;
        // to keep track of the prev node of the current node 

    public:
        Queue(){
            head = tail = nullptr;
        }

        void push(int x){ // = ENQUEUE(x: int)
            Node* newNode = new Node(x, nullptr);

            // Empty dequeue 
            if (head == nullptr){
                // dummyTail = nullptr;
                head = tail = dummyTail = newNode;
            }
            else{ // non-empty queue
                newNode -> setLink(head);
                head = newNode;
            }
        }
        Node* pop(){ // DEQUEUE(x: int)
            // case 1: empty dequeue 
            if (head == nullptr) return nullptr;
            // case 2: one node 
            else if(head -> getLink() == nullptr){
                Node* temp = head;
                delete head;
                head = tail = dummyTail = nullptr;
                return temp;
            }
            else{ // More than one nodes 
                Node* curr = head;
                // while (curr -> getLink() != nullptr){
                //     curr -> setLink(curr);
                // }
                curr = head -> getLink();
                delete head;

                // curr = nullptr;
                return curr;
            }
        }
        // Queue(int a[], int len);
        void inject(int x){
            Node* newNode = new Node(x, nullptr);
            // case 1 
            // if (head == nullptr) push(newNode -> getData()); // not efficient 
            if (head == nullptr){
                head = tail = dummyTail = newNode;
            }
            else{
                dummyTail = tail;
                tail -> setLink(newNode);
                tail = newNode;
            }
        }

        Node* eject(){
            dummyTail -> setLink(nullptr);
            Node* temp = tail;
            delete tail;
            tail = dummyTail;
            return temp;
        }



        // void ENQUEUE(int x){}
        // int* DEQUEUE(){}
};





#endif 