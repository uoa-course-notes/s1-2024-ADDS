#include "Heap.h"


/*******************************/
// default constructor
/*******************************/
template<typename T>
Heap<T>::Heap(){}



template <typename T>
Heap<T>::Heap(std::vector<T> start_values){
    // copy the values into our heap vector 
    for(int i=0; i< start_values.size();i++){
        values.push_back(start_values[i]);
    }

    // Starting from the last non-leaf node (last parent), heapify each of the parents 
    int initial_parent_index = floor(values.size()) - 1;
    for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--){
        heapify(parent_index);
    }
}

/*******************************/
// add values to the heap
/*******************************/
template<typename T>
void Heap<T>::insert(T value){
    // push value into the vector 
    values.push_back(value);

    // Now try to restore heap property, if any of the property has been violated
    int value_index = values.size()-1; // since value is inserted at the last, 
    // let's pass in its parent's index instead 
    int parent_index = floor(int(value_index/2))-1;
    // the last element has to be passed in. 
    heapify(parent_index);
}




/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // TODO: TO BE IMPLEMENTED
  
  // check whether the value exist in our vector
 bool existence = find_value(value);
 if (existence == false) return; // terminate 


 // otherwise 
// delete it 
values.erase(values.begin() + );
 // find the last value to be swapped with the deleted position 
 T last_element = values.at(values.end()-1);

// delete the last element 
 values.pop_back();

 // call heapify by passing in the 



}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  // TODO: TO BE IMPLEMENTED
  return values.at(values.begin()); // return the first element of the vector or the heap 
  // since this is a min heap 
  // but we'll implement getMax() as well. 
}

template<typename T>
bool Heap<T>::find_value(T value){
    for (int i=0; i < values.size(); i++){
        if (value == values.at(i)) return true;
    }
    return false;
}




template <typename T>
T Heap<T>::getMax(){
    int max = 0;


    return max;
}



template<typename T>
 void Heap<T>::pretty_print(){
    std::vector<T> data = values;
    std::cout << "<";
    for (int i=0; i<data.size(); i++){
        if (i == data.size()-1) std::cout << data[i];
        else std::cout << data[i] << ",";
    }
    std::cout << ">" << std::endl;
}



/*******************************/
// private function to heapify a given 'node'
/*******************************/



template<typename T>
void Heap<T>::heapify(int parent_index){
    // if we're outside the index range, terminate the function 
    if (parent_index < 0 || parent_index >= values.size()) return;

    // Find children index 
    int left_child_index = parent_index*2 + 1;
    int right_child_index = parent_index*2 + 2;


    // if parent is lager than child, swap with the smallest child 
    int index_of_smallest = parent_index;


    // Check if the left child exists 
    if (left_child_index < values.size() && values.at(left_child_index) < values.at(index_of_smallest)){
        // update the current smallest index to be the left child index 
        index_of_smallest = left_child_index;
    }


    // Check if the right child exists 
    if (right_child_index < values.size() && values.at(right_child_index) < values.at(index_of_smallest)){
        index_of_smallest = right_child_index;
    }

    // At this point, index_of_smallest should contain the 

    // If parent is not the smallest,
    if (index_of_smallest != parent_index){
        // Swap with the smallest child 
        T temp = values.at(parent_index);
        values.at(parent_index) = values.at(index_of_smallest);
        values.at(index_of_smallest) = temp;
    }

    heapify(floor(parent_index / 2) - 1);
}




template <typename T>
Heap<T>::~Heap(){

}