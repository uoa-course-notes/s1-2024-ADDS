#ifndef HEAP_H
#define HEAP_H

/***************************************/
// Find the smallest value in the heap
/**************************************/



template<typename T>
T Heap<T>::getMin(){
    // TODO: TO-BE IMPLEMENTED
}

/***************************************/
// Private function to heapify a given "node"
/***************************************/


template<typename T>
void Heap<T>::heapify(int parent_index){
    // If we're outside the index range return
    if (parent_index < 0 || parent_index >= values.size()) return;


    // Find childrne indices 
    int left-child_index = parent_index*2 + 1;
    int right_child_index = parent_index *2 + 2;

    // If parent is larger than child, swap with the smallest child
    int index_of_smallest = parent_index;


    // Check is left child exists, and if so, it is the smallest value there
    if (left_child_index < values.size()
        && values.at(left_child_index) < values.at(index_of_smallest)){
        // make this index the current smallest 
        index_of_smallest = left_child_index;
    }


    // check if left child exists 

    if (right_child_index < values.size() && 
        values.at(right_child_index) < values.at(index_of_smallest)
    ){
        // make it the current smallest
        index_of_smallest = left_child_index;
    }

    // If parent is not smallest, swap with the smallest child
    if (index_of_smallest != parent_index){
        T temp = values.at(parent_index);
        values.at(parent_index) = values.at(index_of_smallest);
        values.at(index_of_smallest) = temp;
    }

    // Move up the tree to the grandparents' level
    heapify(floor(parent_index/2) - 1);



}





#endif 