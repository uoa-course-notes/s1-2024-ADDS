#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <sys/types.h>

// #include <conio.h>


void printArray(int* A, int N){
    std::cout << "<";
    
    for(int i=0; i<N; i++){
        if (i==N-1) std::cout << A[i];
        else std::cout << A[i] << ",";
    }
    std::cout << ">" << std::endl;
}

unsigned long int LINEAR_SEARCH(int *A, int N, int key){
    for (int i=0; i<N; i++){
        if (A[i] == key) return (unsigned long int) i;
    }
    return std::string::npos; // invalid position
}


// ------------------ BEWARE -------------
// ==================BUGS BELOW ====================

// int* generate_distinct_element_array(u_int32_t N){ // generate an array of distinct elements of integer from -N to N
//     int* A = new int[N];
//     int element = 0;
//     // A[0] = (rand() % (2*N + 1)) - N;
//     for (int i=0; i<N; i++){
//         element = (rand() % (2*N + 1)) - N;
//         // if the element is found then skip to the next iteration. 
//         if (LINEAR_SEARCH(A, N, element) != std::string::npos){ 
//             std::cout << "Found " << element << std::endl;
//             printArray(A, N);
//             std::cout << "Enter:";
//             // std::cin >> element;
//             getchar();
//             continue;
//         }
//         else A[i] = element;
//     }
//     return A;
// }


// int* generate_distinct_element_array(int N) {
//     int* A = new int[N];
//     int element;
//     int index = 0;
//     bool found;
    
//     // Seed the random number generator
//     // std::srand(std::time(0));
    
//     while (index < N) {
//         element = rand() % (2 * N + 1) - N;
//         found = false;
        
//         // Check if the element is already in the array
//         for (int i = 0; i < index; i++) {
//             if (A[i] == element) {
//                 found = true;
//                 break;
//             }
//         }
        
//         // If the element is not found, add it to the array
//         if (!found) {
//             A[index++] = element;
//         }
//     }
    
//     return A;
// }

bool isDistinct(int* A, int N){
    if (N<1) return false; // an array of 0 element yields false value checkmark
    for (int i=1; i<N; i++){
        if (A[i-1] == A[i]) return false;
    }
    return true; // Every element has been checked by this point. 
    // Thus A is a mututally disitnct array A[i] != A[j] for all i != j. 

}

int* generate_random_array(int N){
    int* A = new int[N];
    for (int i=0; i<N; i++){
        A[i] = (rand() % (2*N + 1)) - N;
    }
    return A;
}


void swap(int& a, int &b){
    int swap = 0;
    swap = a;
    a = b;
    b = swap;
}

void shuffle(int* A, int N){
    int rand_pos = 0;
    for(int i=0 ;i<N; i++){
        rand_pos = rand() % N; // from 0 to N-1
        swap(A[i], A[rand_pos]);        
    }
}


unsigned long int BINARY_SEARCH(int* A, int N, int key, int begin, int end){
    if (N < 1) return A[0];
    else{
        int mid = (begin + end)/2;
        if (key < A[mid]) return BINARY_SEARCH(A, N, key, begin, mid);
        else if(key > A[mid]) return BINARY_SEARCH(A, N,key,mid, end);
        else return mid;
    }
}

bool isSorted(int* A, int N){
    if (N < 1) return false; // array must be at least of length 1
    for (int i=1; i<N; i++){
        if (A[i-1] > A[i]) return false;
    }
    return true;
}

int MIN(int* A, int N){
    int min = A[0];
    for (int i=1; i<N; i++){
        if (A[i] < min) min = A[i];
    }
    return min;
}

// bugs still unchecked 
void SELECTION_SORT(int* A, int N){
    if (N < 1) return;
    int min = 0;
    for (int i=0; i<N ;i++){
        // min = MIN(A, N);
        min = A[i+1];
        // array slicing is very costly...use index-based algorithm instead
        for (int j=i+1; j< N; j++){
            if (A[j] < min) min = A[j];
        }
        swap(A[i], min);
    }
}
// SELECTION SORT recursively...? 



void INSERTION_SORT(int* A, int N){
    for (int i=1; i<N; i++){
        int j = i;
        while (A[j - 1] > A[j] && j >= 1){
            swap(A[j], A[j-1]);
            j--;
        }
    }

}


int main(int argc, char** argv){
    srand(time(nullptr));    
    int N = 10;
    // int* A = generate_random_array(N);
    // std::cout << "Before shuffling" << std::endl;
    // int x = 0;
    // for (int i=0; i<10000; i++){
    //     int* A = generate_distinct_element_array(N);
    //     printArray(A, N);
    // }
    int* A = generate_distinct_element_array(N);
    printArray(A, N);
    if (isDistinct(A,  N)) {
        std::cout << "Distinct" << std::endl;
        // x++;
    }
    else std::cout << "Not distinct" << std::endl;

    // std::cout << "Out of " << 10000 << " randomly generated arrays, only " << x << " are disinct." << std::endl;
    
     
    // printArray(A,  N);
    // for (int i=0; i<10; i++){
    //     std::cout << rand() % (2*10 + 1) - 10 << std::endl;   
    // }
    // shuffle(A, N);
    // std::cout << "After shuffling" << std::endl;
    
    // std::cout << "Before sorting" << std::endl;
    // printArray(A, N);
    // std::cout << "After sorting" << std::endl;
    // // INSERTION_SORT(A, N);
    // SELECTION_SORT(A, N);
    // printArray(A, N);
    // if (isSorted(A, N)) std::cout << "Sorted!" << std::endl;
    // else std::cout << "No" << std::endl;
    

    // delete A;
    return 0;
}