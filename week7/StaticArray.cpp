#include <iostream>
#include <typeinfo>



class staticArray{
    private:
        int* base;
        int capacity;
        int iterator;
    public:
        
        staticArray(int capacity){
            base = new int[capacity];
            this -> capacity = capacity;
            // for(int i=0; i<capacity; i++){
            //     base[i] = 0;
            // }
            iterator = 0;
        }
        staticArray(): staticArray(0){}
        
        bool isEmpty(){
            if (iterator == 0) return true;
            else return false;
        }
        int at(unsigned int index){
            if (isEmpty()) return -1;
            else return *(base + index);
        }
        
        void append(int data){
            // append at the back of the array
            if (iterator == capacity) return; // return to prevent iterator from going above the capacity which is an invalid, and potentially dangerous behavior.

            base[iterator++] = data;
            // std::cout << getIterator() << std::endl;
        }
        
        // This is comparatively the most complicated abstraction to implement as it requires some sophisticated understanding 
        // on indexing the correct allocated memory location. 
        void insertAt(int pos){ // remember that this is a 0-indexing origin data structure 
            if (isEmpty()) return;
            else{
                
            }
        }
        void prettyPrint(){
            std::cout << "<";
            int current = getCurrentSize();
            for (int i=0;i < current; i++){
                if (i == current-1) std::cout << base[i];
                else std::cout << base[i] << ",";
                
            
            }
            std::cout << ">" << std::endl;
        }
        unsigned int getCurrentSize(){
            int current =0;
            // Still a bug over here to be fixed. 
            for (int i=0; i<capacity; i++){
                if (base[i] != 0) ++current; // if the element is not 0, then it is non-zero, then it is counted. 
                else continue;
            }
            return current;
        }

        int getIterator(){return iterator;}
        unsigned int getCapacity(){return capacity;}
            

        ~staticArray(){delete[] base;}

};    




int main(void){
    staticArray array(10);
    // std::cout << array.getCapacity() << std::endl;
    
    array.append(83);
    std::cout << array.getCurrentSize() << std::endl;
    array.append(3);
    std::cout << array.getCurrentSize() << std::endl;
    array.append(-3);
    std::cout << array.getCurrentSize() << std::endl;
    array.append(84);
    std::cout << array.getCurrentSize() << std::endl;
    array.append(-411);
    std::cout << array.getCurrentSize() << std::endl;

	array.prettyPrint();
    

    // std::cout << array.getCapacity() << std::endl;
    // unsigned int x = array.at(0);
    // std::cout << x << std::endl;
    // int x = 1;
    // int* A = new int[x*10];
    

    // delete[] A;
    return 0;
}