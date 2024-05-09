#ifndef NODE_H
#define NODE_H
#include <iostream>


class Node{
    private:
        int data;
        Node* lst;
        Node* rst;
    public:
        Node(int data);
        Node();
        
        void setData(int data);
        int getData();

        void setLST(Node* link);
        void setRST(Node* link);

        Node* getLST();
        Node* getRST();


        ~Node();
};



#endif 