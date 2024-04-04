#include "BubbleSort.h"




std::vector<int> BubbleSort::sort(std::vector<int> A){
    int N  = A.size();
    for (int i=0; i<N-1; i++){
        for(int j=0; j<N-i-1; j++){
            if (A[j] > A[j+1]) swap(A[j], A[j+1]);
            // if (A[j] > A[j+1]) swap(A[j], A[j-1]);
        }
    }
    return A;
}