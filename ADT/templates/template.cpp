#include <iostream>
#include <string>


// void Print(int val){
//     std::cout << val << std::endl;
// }


// void Print(std::string val){
//     std::cout << val << std::endl;
    
// }

// void Print(float val){
//     std::cout << val << std::endl;
// }

template<typename T>
// you can either use typename or class, although typename is syntactically preferrable
void Print(T val){
    std::cout << val << std::endl;
}


// Template is created during compile time and 
// depending on hoow it's called (what type of arguments are passed into the method)
// appropriate method signatures, T is filled by different type. 
// 
template<typename T, int N>
class Array{
    private:
        T* m_Array[N]; // T and N are specified at compiled-time
    public:
        int getSize() const {return N;}


};

int main(int argc, char** argv){
    
    //  We don't even need to specify the type anymore
    Print(5);
    Print("Hello");
    Print(21.1f);    
    
    // Although, we can even specify Hello
    Print<std::string>("Hello"); 
    
    // The template doesn't exist until we call its corresponding method
    // Even if there're syntax errors in the template or method, our code will still compile. 
    // But it's compiler-dependent and it doesn't compile on my machine


    // Templates are not limited to types and functions
    // The standard template library is just a set of templated classes embedded under namespaces for ease of implementation.
    
    // Array<5> array; // Our template argument is 5
    // A version of the class gets created and replaced N with 5
    // So many different versions of that class can be created, we can use string
    // std::cout << array.getSize() << std::endl;

    Array<std::string, 5> array;
    std::cout << array.getSize() << std::endl;
    

// Meta-Programming
// programming compiler behavior at compile-time

    // When to use and when not to use templates
    // 

    return 0;
}