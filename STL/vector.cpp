#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>



#include <vector>



std::vector<int> generate_data(unsigned int N){
    std::vector<int> A;
    for (int i=0; i<N; i++){
        A.push_back(rand()%(2*N) - N);
    }
    return A;
}

void print_data(std::vector<int> A){
    std::cout << "<";
    for (int i=0; i<A.size(); i++){
        if (i== A.size()-1) std::cout << A[i];
        else std::cout << A[i] << ",";
    }
    std::cout << ">" << std::endl;
}

int main(int argc, char** agrv){
    srand(time(nullptr));




    // std::vector<int> A = generate_data(10);
    std::vector<int> A =  {-12,4,32, 21, 328, 218, 129,12};
    sort(A.begin(), A.end());
    print_data(A);

    int key = 9;
    // 
    bool present = std::binary_search(A.begin(), A.end(), key);
    std::cout << present << std::endl;


    // Gives iterator to the first element that is greater than or equal to than 100 
    std::vector<int>::iterator it = std::lower_bound(A.begin(), A.end(), 100);
    // Gives iterator to the first element that is strictly greater than 100 
    std::vector<int>::iterator it2 = std::upper_bound(A.begin(), A.end(), 100);

    std::cout << *it << ", " << *it2 << std::endl;
    std::cout << it2-it << std::endl;


    return 0;
}