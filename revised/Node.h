#pragma once 

class Node{
    private:
        int data;
        Node* link;
    public:
        Node();
        Node(int data, Node* link);
        Node(int data);

        int getData();
        void setData(int data);


        Node* getLink();
        void setLink(Node* link);

        ~Node();


};