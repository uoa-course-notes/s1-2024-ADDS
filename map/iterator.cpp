#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>

int main(int argc, char* argv[]){
    std::vector<int> values = {1,2,4,5,61};

    // How to print out these values? 
    // 5 different ways
    for (int i=0; i<values.size(); i++){
        std::cout << values[i] << std::endl;        
    }


    // Using a range-based for loop, which is preferred when you don't need information about the index
    for (int value: values){
        std::cout << value << std::endl;    
    }
    // /////////////////////////////////////////////////////////////////
    // But, how does the range-based for loop work? 
    // The vector class provides a begin() and end() funtions that return an iterator at a particular position

    for(std::vector<int>::iterator it = values.begin(); 
    it != values.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cin.get();

    // Now every data structure has a "simple" indexing procedure such as array or vector which are stored as contiguous memory in the RAM

    using ScoreMap = std::unordered_map<std::string, int>;
    using ScoreMapConstIter = ScoreMap::const_iterator;
    ScoreMap map;
    // std::unordered_map<std::string, int> map;
    map["Seth"] = 29;
    map["c++"] = 219;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++){
        auto& key = it -> first; // key
        auto& value = it -> second; //value
        std::cout << key << " = " << value << std::endl;
    }
    // But how to improve this code? 
    for (auto kv : map){
        auto& key = kv.first;
        auto& value = kv.second;
        std::cout << key << " = " << value << std::endl;    
    }

    // can we do even better? In C++17, we cna use structure binding
    // So don't forget to compile with C++ 17 or structure binding will not be 
    // supported and erros are thrown
    for (auto [key, value]: map){
        std::cout << key << " = " << value << std::endl;
    }







    return 0;
}