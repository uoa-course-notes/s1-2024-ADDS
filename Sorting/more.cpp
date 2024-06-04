#include <iostream>

void swap(int& a, int& b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void print(int A[], int N){
    std::cout << "<";
    for (int i=0; i< N; i++){
        if (i == N-1) std::cout << A[i];
        else std::cout << A[i] << ",";
    }
    std::cout << ">" << std::endl;
    
}


void SELECTION_SORT(int A[], int N){
    for (int i=0; i < N; i++){
        int minPos = i + 1;
        for (int j = i+1; j < N; j++){
            // print(A, N);
            // std::cin.ignore();
            if (A[j] < A[minPos]) minPos = j;
        }
        swap(A[i], A[minPos]);
   }
}



int main(int argc, char** argv){
    int T[] = {29, 4, 1, 2, 481, 3884, 1009, 4884, 4};
    int N = sizeof(T)/sizeof(T[0]);
    print(T, N);
    SELECTION_SORT(T, N);
    print(T, N);


    return 0;
}