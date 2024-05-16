// #include "Heap.cpp"
#include <iostream>
#include <vector>




std::vector<int> generate_random_data(u_int32_t size){
    std::vector<int> V;
    int e = 0;
    for (unsigned int i=0; i<size; i++){
        e = rand() % (2*size) - 1;
        V.push_back(e);
    }
    return V;
}

void pretty_print(std::vector<int> data){
    std::cout << "<";
    for (int i=0; i<data.size(); i++){
        if (i == data.size()-1) std::cout << data[i];
        else std::cout << data[i] << ",";
    }
    std::cout << ">" << std::endl;
}



////////////////////////////CLSR TO-BE IMPLEMENTED////////////////////////////////
// class Heap{
//     private:
//         int* data;
//         unsigned int size;
//     public:
//         Heap(){}
//         Heap(int* data, int size){

//         }

//         void Heapify(){

//         }

//         /**
//          * @brief Runs in O(nlog(n)) time is the key to maintaining the max-heap property
//          * 
//          */
//         void MAX_HEAPIFY();

//         /**
//          * @brief Runs in O(n) time produces a max-heap from an unordered input array.
//          * 
//          */
//         void BUILD_MAX_HEAP();

//         /**
//         @brief Runs in O(nlogn) sorts an array in-place. 
//         */
//         void HEAPSORT();
        



//         void MAX_HEAP_INSERT();
//         void HEAP_EXTRACT_MAX();
//         void HEAP_INCREASE_KEY();
//         void HEAP_MAXIMUM();
//         /**
//          * @brief The 4 procedures above allows the heap data structure to implement a priority queue. 
//          * 
//          */

//         ~Heap(){}
        

// };
////////////////////////////////////////////////////////////








int main(int argc, char** argv){
    // srand(time(nullptr));
    // // std::vector<int> elements = {1,2,21, 32, 4, 21};
    // int size = 10;
    // const std::vector<int> elements = generate_random_data(size);
    // Heap<int> heap(elements);
    // pretty_print(elements);


    // heap.pretty_print();
    // // test insertion 
    // int element_to_be_inserted = 21;
    // heap.insert(element_to_be_inserted);

    // // Test delete 
    // int element_to_be_deleted = 2;
    // heap.remove(element_to_be_deleted);

    // // Test min 
    // int min_element = heap.getMin();

    std::vector<int> V = {12, 43, 95, 9219, -120, 48, 219};
    V.erase(V.begin());
    pretty_print(V);    




    return 0;
}