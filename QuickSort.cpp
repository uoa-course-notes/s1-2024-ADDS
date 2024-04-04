#include "QuickSort.h"


int PARTITION(std::vector<int>& list, int p, int r){
    
    
    int piv = list[r];
    int i = 0;
    // int j = 0;
    for (int j=0; j<r; i++){
        if (list[j] < piv){
            swap(list[j], list[i]);
            i++;
        }
    }
    swap(list[i+1], piv);
    return i+1;
}


std::vector<int> QS(std::vector<int>& list, int p, int r){
    if (p < r){
        int piv_pos = PARTITION(list, p, r);
        QS(list, p, piv_pos-1);
        QS(list, piv_pos + 1, r);
    }
}


std::vector<int> QuickSort::sort(std::vector<int> list){
    return QS(list, 0, list.size()-1);
}