// #include <iostream>
// #include <string>
#include "shuffle.cpp"

// extern int* generate_random_array(int N);
// extern void printArray(int* A, int N);

void MERGE(int* A, int p, int q, int r){
    int n_L = q-p+1;
    int n_R = r-q; 

    int* L = new int[n_L];
    int* R = new int[n_R];

    for(int i=0; i<n_L; i++){
        L[i] = A[p+i];
    }

    for(int j=0; j<n_R; j++){
        R[j] = A[p+j];
    }

    int i = 0;
    int j = 0;
    int k = p;
    while (i < n_L && j < n_R){
        if (L[i] < R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }



    // Copy the remaining elements in each subarray 
    while (i < n_L){
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n_R){
        A[k] = R[j];
        j++;
        k++;
    }


    delete[] L;
    delete[] R;
}


void MERGE_SORT(int* A, int p, int r){
    if (p >= r) return;
    else{
        int q = (p+r)/2;

        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE(A, p, q, r);
    }
}





int main(int argc, char** argv){
    srand(time(nullptr));
    int size = 10;
    int* A = generate_random_array(size);
    std::cout << "Before sorted: " << std::endl;
    printArray(A, size);
    
    MERGE_SORT(A, 0, size);
    std::cout << "After sorted: " << std::endl;
    printArray(A, size);


    if (isSorted(A, size)){
        std::cout << "Sorted" << std::endl;
    }
    else std::cout << "Not sorted" << std::endl;


    delete[] A;
    return 0;
}