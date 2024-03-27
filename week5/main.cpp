#include <iostream>

#include <vector>

int GCD(int a, int b){
    while(b!=0){
        int remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
}


// Maximum subsequence - subproblem
int ALG1_subseq(std::vector<int> s){
    for(size_t i =0; i<s.size(); i++){
        int sum = 0;
            for(size_t k =0; k<= i; k++){
                
            }
    }

    return 0;
}

int ALG2_subseq(std::vector<int> s){
    int max = 0;

    return max;
}


// Maximum subarray Divide and Conquer


// Kadan's algorithm
int maxSubArray(std::vector<int> s){
    int sum = 0, maxSum = 0;
    for (int i=0; i< s.size(); i++){
        sum += s.at(i);
        if (sum > maxSum) maxSum = sum;
        else if(sum < 0) sum = 0;
    }
    return maxSum;
}

int main(int argc, char** argv){
    std::vector<int> S = {2,12,3,1,-1,21,2, -2, -4, -9, 29};
    int X = maxSubArray(S);
    std::cout << X << std::endl;


    
    return 0;    
}

/*
1. Can algorithm be implemented using recursion? 

*/