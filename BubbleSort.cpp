#include "BubbleSort.h"




std::vector<int> BubbleSort::sort(std::vector<int> A){
    int N  = A.size();
    for (int i=1; i<N; i++){
        for(int j=1; j<N; j++){
            if (A[j-1] > A[j]) std::swap(A[j], A[j-1]);
            // if (A[j] > A[j+1]) swap(A[j], A[j-1]);
        }
    }
    

    return A;
}