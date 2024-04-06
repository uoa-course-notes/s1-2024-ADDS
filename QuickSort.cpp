#include "QuickSort.h"




int QuickSort::PARTITION(std::vector<int>& list, int p, int r){   
    // std::cout << "In PARTITION\n";
    int piv_subindex = 0;
    if (r > 3){
        piv_subindex = 3;
        // std::cout << "piv_subindex is 3" << std::endl;
    }
    else piv_subindex = r;
    // std::cout << "piv_subindex = " << piv_subindex << std::endl;

    int piv = list[piv_subindex];
    int i = 0;
    // int j = 0;
    for (int j=0; j<r; j++){
        // std::cout << "In for loop\n";
        std::cin.ignore();
        if (list[j] < piv){
            // std::cout << "In if\n";
            std::swap(list[j], list[i]);
            i++;
        }
    }
    // std::cout << "i+1 = " << i+1; 
    std::swap(list[i+1], piv);
    return i+1;
}





std::vector<int> QuickSort::QS(std::vector<int>& list, int p, int r){
    if (p < r){
        // std::cout << "Hello, world" << std::endl;
        
        int piv_pos = PARTITION(list, p, r);
        QS(list, p, piv_pos-1);
        QS(list, piv_pos+1, r);
        return list;
    }
    // return list;
    // return nullptr;
}


std::vector<int> QuickSort::sort(std::vector<int>& list){
    return QS(list, 0, list.size()-1);
}