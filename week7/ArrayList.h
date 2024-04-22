#ifndef Array_List_H
#define Array_List_H

#include "LinearList.h"

template<class T>
class arrayList: public linearList<T>{
    public:
        // constructors, copy constructor and destructor
        arrayList(int initialCapacity=10);
        arrayList(const arrayList<T>&);

        // ADT methods
        bool empty() const;
        int size() const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T* theElement);
        void output(std::ostream out) const;

        // Additional method
        int capacity() const;
    protected:
        void checkIndex(int theIndex) const;

        T* element; // 1D array to hold list of elements
        int arrayLength; // capacity of the 1D array
        int listSize; // number of elements in list
        

};




#endif 