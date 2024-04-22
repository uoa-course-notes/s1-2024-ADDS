#include "ArrayList.h"
#include <algorithm>
#include <sstream>
#include <stdexcept>



template<class T>
arrayList<T>::arrayList(int initialCapacity){
    // Constructor
    if (initialCapacity < 1) {
        std::ostringstream s;
        throw std::invalid_argument(s.str());
        // throw illegalParameterValue(s.str());
    }
    // else
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}


template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList){
    arrayLength = theList.size();
    element = new T[arrayLength];
    std::copy(theList.element, theList.element + listSize, element);
}


