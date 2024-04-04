#ifndef RECURSIVE_BINARY_SEARCH_H
#define RECURSIVE_BINARY_SEARCH_H
#include "Sort.h"


class RecursiveBinarySearch{
    public:
        bool search(std::vector<int> list, int key);
        // bool BINARY_SEARCH(std::vector<int> list, int key, int begin, int end);
        bool binarySearch(std::vector<int> array, int x, int low, int high);



};



#endif