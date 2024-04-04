#include "RecursiveBinarySearch.h"


void printVector1(std::vector<int> V){
    int N = V.size();
    // std::cout << "<";
    for (int i=0; i<N; i++){
        if(i == N-1) std::cout << V[i];
        else std::cout << V[i] << " ";
    }
    // std::cout << ">" << std::endl;
    std::cout << std::endl;
    
}


bool RecursiveBinarySearch::BINARY_SEARCH(
    std::vector<int> list,
    int key, 
    int begin, int end)
{
    int mid = (begin + end)/2;
    std::cout << "mid = " << mid << "\t";
    printVector1(list);
    
    
    if (key > list[mid]) return BINARY_SEARCH(list, key, mid, end);
    else if(key < list[mid]) return BINARY_SEARCH(list, key, begin, mid);
    else return true; // A[mid] == key
    
    // At this point, key is not in the list
    return false;
}


bool RecursiveBinarySearch::search(std::vector<int> list, int key){
    return BINARY_SEARCH(list, key, 0, list.size()-1);
}