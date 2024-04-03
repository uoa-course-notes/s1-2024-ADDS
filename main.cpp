#include "BubbleSort.h"
#include "Sort.h"
#include <exception>
// #include <stdexcept>
#include <ctime>
#include "RecursiveBinarySearch.h"
#include "QuickSort.h"



std::vector<int> generateRandom(int N){
    std::vector<int> V;
    for (int i=0; i < N; i++){
        V.push_back(rand() % (2*N+1) - N);
    }
    V.push_back(1);
    return V;
}
// template <typename T>
void print_value(char** A, int num){
    // there are "num" number of chracter
    for (int i=0; i<num; i++){
        // try{
        if (A[i] != nullptr){
            for (int j=0; A[i][j] != '\0'; j++)
            {
                    std::cout << A[i][j];
            }
            std::cout << std::endl;
        }
        else {
            // throw std::exception();
            throw std::runtime_error("Error -- trying to dereference nullptr");
        }
        // }
        // }catch(std::exception& ex){
        //     std::cout << "Dereferencing nullptr caught" << std::endl;
        //     // std::cout << "A nullptr has been caught" << std::endl;
        //     return;
        // }
        
    }
    std::cout << std::endl;
    
}


void printVector(std::vector<int> V){
    int N = V.size();
    // std::cout << "<";
    for (int i=0; i<N; i++){
        if(i == N-1) std::cout << V[i];
        else std::cout << V[i] << " ";
    }
    // std::cout << ">" << std::endl;
    std::cout << std::endl;
    
}



bool BINARY_SEARCH(
    std::vector<int> list,
    int key, 
    int begin, int end)
{
    int mid = (begin + end)/2;
    
    if (key > list[mid]) return BINARY_SEARCH(list, key, mid, end);
    else if(key < list[mid]) return BINARY_SEARCH(list, key, begin, mid);
    else return true; // A[mid] == key
    
    // At this point, key is not in the list
    return false;
}
void swap(int&a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void BUBBLE_SORT(std::vector<int>& A){
    int N  = A.size();
    for (int i=1; i<N; i++){
        for(int j=1; j<N; j++){
            if (A[j-1] > A[j]) swap(A[j], A[j-1]);
            // if (A[j] > A[j+1]) swap(A[j], A[j-1]);
        }
    }
}

void RecursiveBubble(std::vector<int>& A, int k){
    if (k==0) return;
    else{
        for (int i=1; i<k; i++){
            if (A[i-1] > A[i]) swap(A[i-1], A[i]);
        }

        RecursiveBubble(A, k-1);
    }
}
// Check if the array is sorted correctly in ascending order. 
bool isSorted(std::vector<int> list, int N){
    // int N = list.size();
    for(int i=1; i<N; i++){
        if (list[i] < list[i-1]) return false;
    }
    return true;
}

void isSorted(std::vector<int> list){
    if (isSorted(list, list.size()) == true) std::cout << "Sorted" << std::endl;   
    else std::cout << "Not sorted" << std::endl;
}

void INSERTION_SORT(std::vector<int> A){
    int N = A.size();
    for (int i=1; i<N; i++){
        int key = A[i];
        int j = i;
        while (A[j] <= A[j-1] && j > 0){   
            A[j] = A[j-1];
            j--;
        }
        A[j+1] = key;
        printVector(A);
    }
}

// std::vector<int> convert_to_vector(std::string s){
//     return {};
// }

int main(int argc, char** argv){
    // srand(time(nullptr));
    // std::cout << "How many command line arguments were there? " << argc << std::endl ;
    // std::cout << "And what are they? " << std::endl;
    // int i = 0;
    // // std::string* A[10] = {};
    // std::string x = "";
    // print_value(argv, argc);
    // std::cout << "Enter a string: ";
    // while (std::cin >> x){
    //     std::cout << "Enter a string: ";
    //     // A[i++] = x;

    //     // argv
    // }
    // char ** A = new char*[10];
    // char* a1 = "hello";
    // char* a2 = (char*) "hello1";
    // char* a3 = (char*) "hello2";
    // char* a4 = (char*) "hello3";
    // // std::cout << a1 << std::endl;
    // A[0] = a1;
    // A[1] = a2;
    // A[2] = a3;
    // A[3] = a3;
    // A[4] = a4;
    // print_value(A,10);
    // std::cout << "Before sorting" << std::endl;
    // printVector(list);
    // std::cout << "After sorting" << std::endl;
    // // // BUBBLE_SORT(list);
    // INSERTION_SORT(list);
    // // RecursiveBubble(list,  size);
    // isSorted(list);
        // int x = 0;
    // while (std::cin >> x){
    //     list.push_back(x);
    // }


    // Get user input using getline instead...
    int key = 1;
    // std::string String_formatted_array;
    // std::getline(std::cin, String_formatted_array);
    // int x = 2;
    // std::cout << "Before swapping: " << key << "," <<  x << std::endl;
    // std::swap(key,x);
    // std::cout << "After swapping: " << key << "," <<  x << std::endl;
    int num;
    // std::vector<int> list = generateRandom(size);
    std::vector<int> list;
    // std::cout << "Enter a number:" << std::endl;
    
    // int size = 0;
    while (std::cin >> num){
        list.push_back(num);
        // size = array.size();
        if (std::cin.eof()) break;
        // std::cout << "Size: " << size << std::endl;
    }

    
    // Sort String_formatted_array in ascending order using quick sort
    Sort* bubble_sort = new BubbleSort();
    // printVector(list);
    list = bubble_sort -> sort(list);
    // int i = 0;
    // while (i<100){
    //     list = bubble_sort -> sort(list);
    //     if (isSorted(list, size) != true) break;
    //     else i++;
    // }

    // if (i == 100) std::cout << "Bubble sort checks out!" << std::endl;
    // else std::cout << "Something wrong with bubble sort" << std::endl;
    // std::cout << i << std::endl;
    
    RecursiveBinarySearch* searcher;
    bool found = searcher -> search(list, key);
    if (found == true) std::cout << "true";
    else               std::cout << "false";
    std::cout << " ";
    
    printVector(list);
    // if (found != true) std::cout << "Nope" << std::endl;
    // else std::cout << "Yes" << std::endl;
    


    // Use Binary search to determine whether 1 belongs to the list or not 



    // std::cout << "Hello " << String_formatted_array << std::endl; 


    

}