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
        MERGE(A, p, q+1, r);
    }
}


template<typename E, typename C>
void merge(std::vector<E>& in, std::vector<E>& out, const C& less, int b, int m){
    int i = b;
    int j = b+m;
    int n = in.size();
    int e1 = std::min(b+m, n);
    int e2 = std::min(b+2*m, n);

    int k = b;
    while ((i < e1) && (j < e2)){
        if (in[j] <= in[i]) out[k++] = in[i++];
        else out[k++] = in[j++];
    }

    while (i < e1) out[k++] = in[i++];

    while (j < e2) out[k++] = in[j++];
}


template<typename E, typename C>
void mergeSort(std::vector<E>& S, const C& less){
    typedef std::vector<E> vect;
    int n = S.size();
    vect v1(S); vect* in = &v1;
    vect v2(S); vect* out = &v2;

    for (int m=1; m<n; m*=2){
        for (int b=0; b<n; b+=2*m){
            merge(*in, *out, less,b,m);
        }
        std::swap(in, out);
    }
    S = *in;
}



void INSERTION_SORT(int* A, int N){
    int key = 0;
    int j = 0;
    for (int i=1; i<N; i++){
        key = A[i];
        j = i-1;
        while(j > -1 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}


// void SELECTION_SORT(int* A, int N){
//     int min_index = 0;
//     for (int i=1; i<N-1; i++){
//         for (int j=i; j<N-1; j++){
//             if (A[j] < A[min_index]) min_index = j;
//         }
//         swap(A[i-1], A[min_index]);
//     }
// }


void SELECTION_SORT(int* A, int N){
    int min_index = 0;
    for (int i=0; i<N-1; i++){
        // std::cout << "Outer loop #" << i << std::endl;
        // std::cin.ignore();
        min_index = i;
        // std::cout << "Inner loop#" << i+1;
        // printArray(A, N);
        for (int j=i+1; j<N; j++){
            if(A[j] < A[min_index]) min_index = j;
        }
        swap(A[i], A[min_index]);
        // printArray(A, N);
        // std::cout << "min_index = " << min_index << " swapped with " << "A["<< i << "]" << " = " << A[i] << std::endl;
    }
}





int main(int argc, char** argv){
    srand(time(nullptr));
    int size = 7;
    // for (int i=0; i<100; i++){
    // int* A = generate_random_array(size);
    int A[] = {6,1,-2,-3,-3,7,4};
    printArray(A, size);
    SELECTION_SORT(A, size);
    printArray(A, size);
    if (isSorted(A, size)) std::cout << "Sorted" << std::endl;
    else {
        std::cout << "Uh oh" << std::endl;
        // break;
    }
    

    
    // std::cout << "Before sorted: " << std::endl;
    // // printArray(A, size);
    // std::vector<int> X = {432, 32, 48, -32, 328, 21, -39};
    // // MERGE_SORT(A, 0, size);
    // for (auto a: X){
    //     std::cout << a << ",";
    // }

    // mergeSort(X, X.size());
    // std::cout << "\nAfter sorted: " << std::endl;
    // // printArray(A, size);
    // for (auto a: X){
    //     std::cout << a << ",";
    // }
    // std::cout  << std::endl;
    
    // if (isSorted(A, size)){
    //     std::cout << "Sorted" << std::endl;
    // }
    // else std::cout << "Not sorted" << std::endl;


    // delete[] A;
    return 0;
}