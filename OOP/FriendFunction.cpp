#include <iostream>
/*
When we say B is a friend class of A. Then B can access A's private and protected members. 
*/

class EquilateralTriangle{
    private:
        float a;
        float circumference;
        float area;
        friend class Homework;
    public:
        void setA(float length){
            a = length;
            circumference = a*3;
            area = (1.73 * a * a)/4;
        }
        // Make the global function PrintResults a friend of Equilateral Triangle 
        // friend void PrintResults(EquilateralTriangle);
        
        // A class can have multiple friend functions 
        // However, choose your friend functions carefully. 
        // If one chooses too many friend functions, that will break the contract of encapsulation. 
        // Since encapsulation dictates that there are certain attributes of a class that shouldn't be seen or exposed to other scopes. 

};

class Homework{
    public:
        void PrintResults(EquilateralTriangle et){
            std::cout << "Circumference = " << et.circumference << std::endl;
            std::cout << "Area = " << et.area << std::endl;
        }


};


/*
Tips:
+ Use this friend function/class concepts sparingly. 
+ Friendship is not an equivalence relation. 
    - Friend is not symmetric (it is not mutual). 
+ Friendshop is not inherited. Suppose we have a base class A and a derived class B. We have a class C. 
Assume that C is a friend class of the base class A then it's not the case that C is also friend class of the base class's derived class, B. 
+


Homework: 
- Watch overloading operator videos. Replace structure with class and resolve 
any bugs by using friend function or friend class. 
*/



int main(int argc, char** argv){
    EquilateralTriangle et;
    et.setA(3);
    // PrintResults(et); // Since PrintResults() is not a global function, it does not exist in the global scope. 
    // Not it exists as only a member method of the Homework class and as member, to invoke it, we need an object of that clas 
    Homework h;
    h.PrintResults(et); 






    return 0;
}
