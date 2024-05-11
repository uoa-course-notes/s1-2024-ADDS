#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <unordered_map>



class Node{
    private:
        std::unordered_map<std::string, Node*> children;
        bool isEndWord;
        friend class Trie;
    public:
        Node();

};




#endif 