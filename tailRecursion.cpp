#include <iostream>

// The correct implementation shouldn't depend on global or static variables
int tailRecursion(int n, int acc = 1){
    if (n == 0) return acc;
    else return tailRecursion(n-1, n * acc);
    // return n;
}

int recursion(int n){

    return tailRecursion(n);
}


int FIB(int n){
    if (n == 0 | n == 1) return 1;
    else return FIB(n-1) + FIB(n-1);
}

int sum(int n){
    if (n == 1) return 1;
    else return n + sum(n-1);
}

int sum_tail(int n, int acc){
    if (n == 1) return acc;
    else return sum_tail(n-1 , n + acc);
}

int sum_normal(int n){
    // if (n == 1) return 1;
    // else return n + sum_normal(n-1); 
    return sum_tail(n, 1);
}





// sum(n)
// 
// 

// Medium problems 






// Dynamic Programming to solve the recursion log: 
// Memoisation
// Solving intermediate result and to avoid computing them again


// Tabulation
// Storing previous values 
// Iteratively use those stored values to compute the next value. 
//
//


int main(int argc, char** argv){
    int n = 100;
    // 1 1 3 
    // std::cout << "FIB(" << n << ") = " << FIB(n) << std::endl;
    std::cout << sum(n) << std::endl;
    std::cout << sum_normal(n) << std::endl;
    
    // std::cout << recursion(10) << std::endl;

    return 0;
}