#include "Autocomplete.h"
#include "PrefixMatcher.h"




void printSuggestions(std::vector<std::string>& suggestions)
{
    for (const auto & a: suggestions){
        std::cout << a << std::endl;
    }
}

int main(int argc, char** argv){
    Autocomplete wordGen;
    wordGen.insert("banana");
    wordGen.insert("bandaid");
    wordGen.insert("bandana");


    
    std::string typedWord = "ban";
    std::vector<std::string> suggestions = wordGen.getSuggestions(typedWord);
    
    // printSuggestions(suggestions);


    PrefixMatcher pm;
    std::string add1 = "1010101";
    int rNumber1 = 1;
    pm.insert(add1, rNumber1);
    
    std::string networdAddress = "10101010";
    pm.selectRouter(networdAddress);
    return 0;
}