#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H
#include "Trie.h"


class PrefixMatcher{
    private:
        Trie t;
        std::unordered_map<std::string, int> router_map;
    public:

        
        // returns the router with the longest matching preifx
        // The argument is a string to ease the implementation
        // A binary number can also be used as an argument. 
        int selectRouter(std::string networdAddress);


        // Add a router address
        void insert(std::string address, int routerNumber);

        // Implementing Patricia Trie data structure as an optimization for Trie 


        // Marking scheme 
        // Interface: Compiles with test main which uses interfaces
        // Functionality(5 marks): passes autograder results 

};


#endif 