#pragma once 

#include <string>
#include <vector>
#include <iostream>

#include <unordered_map>

/* ADT (Interfact) or specifications:



*/
class Node{
    private:
        char a;
        std::unordered_map<char, Node*>  childrenNodes;
    public:
               
};