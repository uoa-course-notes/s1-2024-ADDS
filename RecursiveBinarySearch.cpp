#include "RecursiveBinarySearch.h"



bool RecursiveBinarySearch::BINARY_SEARCH(
    std::vector<int> list,
    int key, 
    int begin, int end)
{
    int mid = (begin + end)/2;
    
    if (key > list[mid]) return BINARY_SEARCH(list, key, mid, end);
    else if(key < list[mid]) return BINARY_SEARCH(list, key, begin, mid);
    else return true; // A[mid] == key
    
    // At this point, key is not in the list
    return false;
}


bool RecursiveBinarySearch::search(std::vector<int> list, int key){
    return BINARY_SEARCH(list, key, 0, list.size()-1);
}