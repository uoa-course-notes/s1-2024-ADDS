#include <iostream>
#include <string>
#include <vector>


void printIndices(int X[], int N){
    // for (auto x: X){
    //     std::cout << x << std::endl;   
    // }
    for (size_t i = 0; i<N; i++){
        // if (X[i] == "") continue;
        std::cout << X[i] << std::endl;   
    }
}

void PrintString(std::string& str){
    std::string a = "Hello ";
    a += str;
    std::cout << a << std::endl;
     
}


bool contains(std::string T, std::string P){
    return T.find(P) != std::string::npos;
}

void printVector(std::vector<int> V){
    for (auto a: V){
        std::cout << a << std::endl;
        
    }
}

void firstOccurences(std::string T, std::string P){
    int N = T.size(), M = P.size();
    int j = 0;
    // Using the fact that the maximum number of occurence P can appear inside T is N
    // That is when T is an amalgamation of N P's conconcetanted together. 
    // int* X = new int[N];
    int X[N];
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
void firstIndices(std::string T, std::string P){
    int N = T.size(), M = P.size();
    int j = 0;
    int X[N];
    int k = 0;


    
}
std::vector<int> findSubstrings(std::string s1, std::string s2){
    std::vector<int> result;
    for (size_t i=1; i<= s2.size(); i++){
        size_t found = s1.find(s2.substr(0, i));

        if (found != std::string::npos) result.push_back(found);
        else result.push_back(-1);
    }
    return result;
}

// Find prefixes of s2 in s1
void findPrefixes(std::string s1, std::string s2){
    int A[s1.size()];
    std::string s = "";
    for (int i=0; i<s2.size(); i++){
        // for(int j=0; j <= i; j++){
        //     std::cout << s2[j] << " ";
        // }
        // std::cout << std::endl;
        s += s2[i];
        for (int j=0; j < s1.size(); j++){
            
        }

    }
}


std::vector<int> rabin_karp(std::string const& s, std::string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    std::vector<long long> p_pow(std::max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    std::vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    std::vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}


std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}



int main(int argc, char** argv){
    // const std::string T = "ATAGCTCGCTTAGCTGGCATGCT";// a constant array of characters 
    // std::cout << argc << std::endl;
    
    // std::string P = "GCT";
    std::string T = "4634554567";
    std::string P = "45689";
    // std::cout << P.substr(0,2) << std::endl;

    // findPrefixes(T, P);
    // std::vector<int> result = findPrefixOccurrences(T, P);
    // printVector(result);
    // printVector(rabin_karp(T, P));
    // T[0] = "";
    // firstOccurences(T, P);
    // std::vector<int> V = findSubstrings(T,P);
    // printVector(V);
    // PrintString(P);

    return 0;
}