#include "Finder.h"



std::vector<int> Finder::findSubstrings(std::string s1, std::string s2){
    std::vector<int> result;
    for (size_t i = 1; i <= s2.size(); i++){
        size_t found = s1.find(s2.substr(0, i));
        if (found != std::string::npos) result.push_back(found);
        else result.push_back(-1);
    }

    return result;

}



/*
Algorithm Can the algorithm be optimized?
1. Find operations that are performed several times.
2. Try to avoid them. Hint: s1.find(s2, index) can find substrings starting from index.
3. If prefix was not found (-1 as an output), the larger prefix will not be found either.
4. What will be the time complexity of the optimized algorithm?


*/