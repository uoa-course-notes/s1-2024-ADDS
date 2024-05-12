#include "Autocomplete.h"
#include "PrefixMatcher.h"
#include <algorithm>


int main(int argc, char** argv){
    Autocomplete wordGen;
    wordGen.insert("banana");
    wordGen.insert("bandaid");
    wordGen.insert("bandana");


    
    std::string typedWord = "ban";
    std::vector<std::string> suggestions = wordGen.getSuggestions(typedWord);
    
    for (auto suggestion: suggestions){
        std::cout << suggestion << std::endl;
    }

    return 0;
}