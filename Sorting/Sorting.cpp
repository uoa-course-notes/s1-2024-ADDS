#include <iostream>

#include <vector>


void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int PARTITION(std::vector<int>& A, int p, int r){
    int x = A[r]; // let the last element be the pivot for now 
    int i = p-1;
    for (int j=p; j<r; j++){
        if (A[j] <= x){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void QUICKSORT(std::vector<int>& A, int p, int r){
    int q = 0;
    if (p<r){
        q = PARTITION(A, p, r);
        QUICKSORT(A, p, q-1);
        QUICKSORT(A, q+1, r);
    }
}


std::vector<int> sort(std::vector<int>& list){
    QUICKSORT(list, 0, list.size()-1);
    return list;
}


void printArray(std::vector<int> A, int N){
    std::cout << "<";
    for (int i=0; i<N; i++){
        if (i == N-1) std::cout << A[i];
        else std::cout << A[i] << ",";   
    }
    std::cout << ">" << std::endl;   
}

int main(int argc, char** argv){
    std::vector<int> A = {7,2,1,6,8,5,3,4};
    int size = A.size();
    printArray(A, size);
    sort(A);
    printArray(A, size);

}