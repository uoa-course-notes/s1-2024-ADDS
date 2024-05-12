#include "Autocomplete.h"
#include "PrefixMatcher.h"
#include <unordered_map>




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


    std::cout << "Testing autocomplete class" << std::endl;    
    std::string typedWord = "ban";
    std::vector<std::string> suggestions = wordGen.getSuggestions(typedWord);
    
    printSuggestions(suggestions);

    std::cout << "Testing prefixMatcher class" << std::endl;
    PrefixMatcher pm;
    std::string add1 = "1100110111";
    int rNumber1 = 1;

    std::string add2 = "110011011";
    int rNumber2 = 2;


    std::string add3 = "11001101";
    int rNumber3 = 3;


    pm.insert(add1, rNumber1);
    pm.insert(add2, rNumber2);
    pm.insert(add3, rNumber3);
    

    // Let's see what's in map is what we have expected 
    std::unordered_map<std::string, int> testMap = pm.getMap();
    for (const auto& [address, routerNumber]: testMap){
        std::cout << address << " : " << routerNumber << std::endl;
    }
    
    std::string networdAddress = "110011011001";
    int selectedRouter = pm.selectRouter(networdAddress);
    std::cout << selectedRouter << std::endl;
    // if (selectedRouter == 2){
    //     std::cout << "Router2 selected! Great job!" << std::endl;
    // }
    // else{
    //     std::cout << "Something wrong. Router #" << selectedRouter << " selected instead\n";  
    // }

    return 0;
}