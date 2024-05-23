#include <iostream>
#include <set>


int main(int argc, char** argv){
    std::set<int, std::less<int>> seth = {13, 5, 32, 21, -10, 20, 19};
    seth.insert(10);
    seth.insert(933);

    for (std::set<int>::iterator it = seth.begin(); it != seth.end(); it++){
        std::cout << *it << ",";
    }
    // our seth will be printed outin ascending order. 
    std::cout << std::endl;


    seth.insert(129);
    
    auto it = seth.find(-20);
    if (it == seth.end()){ // if -20 is not present, seth returns the end() operator 
        // -20 is not present in our set
        std::cout << "Not present" << std::endl;
    }
    else std::cout << "Present" << std::endl;

    // First element in seth that is strictly greater than or equalt o -2 
    auto it3 = seth.upper_bound(-23);
    auto it2 = seth.lower_bound(32);

    std::cout << *it3 << std::endl;


    // We can also erase an element from a set in logN time 


    return 0;
}