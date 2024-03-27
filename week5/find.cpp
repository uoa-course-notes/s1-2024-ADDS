#include <iostream>
#include <string>

template <typename T>
void printIndices(T X[], int N){
    // for (auto x: X){
    //     std::cout << x << std::endl;   
    // }
    for (size_t i = 0; i<N; i++){
        // if (X[i] == "") continue;
        std::cout << X[i] << std::endl;   
    }
}


void firstOccurences(std::string T, std::string P){
    int N = T.size(), M = P.size();
    int j = 0;
    // Using the fact that the maximum number of occurence P can appear inside T is N
    // That is when T is an amalgamation of N P's conconcetanted together. 
    int* X = new int[N];
    int k = 0;
    for(int i=0; i<N; i++){
        if(T[i] == P[j] && j < M){
            // std::cout << P[j] << "=" << T[i] << std::endl;
            
            // std::cout << "Comparing<" << T[i] << "," << P[j] << ">"  << std::endl;
            // Once this condition is reached, we have found the pattern P
            // inside T
            if (j == M-1){
                X[k] = i-M + 1; // We don't directly save index into X, we need to 
                // subtract the current index i with M as the size of P to get to
                // T[i]'s starting index.
                // std::cout << T[i-M + 1] << "-->" << i-M+1 << std::endl;
                
                k++; // And then increment k by 1 to be a placeholder for the 
                // next occurence of the pattern if such a pattern exists after 
                // the current index i of T.              
            }
            j++;
        }
        else j = 0;
    }
    printIndices(X, k);
}

int main(int argc, char** argv){
    std::string T = "ATAGCTCGCTTAGCTGGCATGCTASDGCTAKSJGCTASKGCT";    
    std::string P = "GCT";

    firstOccurences(T, P);

    return 0;
}