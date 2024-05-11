#include "Autocomplete.h"


void Autocomplete::insert(std::string word){
    t.insert(word);
}

std::vector<std::string> Autocomplete::getSuggestion(std::string partialWord){
    std::string prefix;
    std::vector<std::string> parent;
    Node* node = t.navigate(partialWord, prefix, parent);


    std::vector<std::string> result;
    if (prefix == partialWord) t.dfs(node, partialWord, result);
    
    return result;
}




