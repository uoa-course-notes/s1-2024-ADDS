#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>



/*

Class: Sort
--------------------------
This class serves as the base class to be derived by other classes of sorting algorithms. 

*/

class Sort{
    public:
        virtual std::vector<int> sort(std::vector<int> list) = 0;
        
};


#endif