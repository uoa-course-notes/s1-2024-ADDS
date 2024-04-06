#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Sort.h"

class QuickSort: public Sort{
    public:
        int PARTITION(std::vector<int>& list, int p, int r);
        std::vector<int> QS(std::vector<int>& list, int p, int r);
        std::vector<int> sort(std::vector<int>& list) override;
};



#endif