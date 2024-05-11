#ifndef __AUTO_COMPLETE_H__
#define __AUTO_COMPLETE_H__
#include "Trie.h"


class Autocomplete{
    private:
        Trie t;
    public:
        

        // Return the known words that start with partialWord
        std::vector<std::string> getSuggestions(std::string partialWord);

        // Add a word to the set of known words. 
        void insert(std::string word);


        /*
        Example: Suppose the Autocomplete object currently contains the words {bin, ball, ballet}

        As the user types letters (assuming they are going for ballet): 
        Check suggestions for 
        - "b": getSuggestions() returns all 3 words  
        - "ba":getSuggestions() returns "ball" and "ballet" 
        - "bal":getSuggestions() returns "ball" and "ballet"
        - "ball":getSuggestions() returns "ball" and "ballet"
        - "balle":getSuggestions() returns "ballet" as this is the only word that matches the given partilWord = "balle"
        
        */
};



#endif