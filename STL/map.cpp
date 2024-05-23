#include <iostream>
#include <unordered_map>


int main(){
    std::unordered_map<char, int> myMap;
  

    // for (std::unordered_map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); it++){
    //     std::cout << myMap[2] <<std::endl;
    // }


    // Count frequency of each letter 
    std::string word = "hello,world";
    for (auto ch: word){
        myMap[ch]++;
    }

    for (std::unordered_map<char, int>::iterator it = myMap.begin();  it != myMap.end(); it++){
        std::cout << myMap[]];
    }



    return 0;
}