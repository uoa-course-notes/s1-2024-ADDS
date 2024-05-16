#ifndef HEAP_H
#define HEAP_H
#include <iostream>

#include <vector>
#include <cmath>  // for floor

#include <random>
#include <ctime>



template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
  T getMax();

  bool find_value(T value);


  void pretty_print();



  ~Heap();
};




#endif