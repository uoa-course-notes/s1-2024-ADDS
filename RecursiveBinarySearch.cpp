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
bool RecursiveBinarySearch::binarySearch(std::vector<int> array, int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return true;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return false;
}

// bool RecursiveBinarySearch::BINARY_SEARCH(
//     std::vector<int> list,
//     int key, 
//     int begin, int end)
// {
//     if (end - begin == 1){
//         if (list[begin] == key) return true;
//         else return false;
//     }

//     else{
//         int mid = (end-begin)/2;
//         // std::cout << "begin = " << begin << " end = " << end << " mid = " << mid << " --> ";
//         // printVector1(list);
//         // std::cin.ignore();
//         if (list[mid] == key) return true;
//         else if(key < list[mid]) return BINARY_SEARCH(list, key, begin, mid);
//         else return BINARY_SEARCH(list, key, mid, end);

//         // bugs in the implementation below...
//     // if (key > list[mid]) return BINARY_SEARCH(list, key, mid, end);
//     // else if(key < list[mid]) return BINARY_SEARCH(list, key, begin, mid);
//     // else return true; // A[mid] == key


//     // Actually, I forgot that there must exist a base case, if not that would result in an infinite recursion but instead a segmentation fault occurred instead, curiouser and curiouser. 
//     }   
// }


bool RecursiveBinarySearch::search(std::vector<int> list, int key){
    // return BINARY_SEARCH(list, key, 0, list.size()-1);

    return binarySearch(list, key, 0, list.size()-1);
}