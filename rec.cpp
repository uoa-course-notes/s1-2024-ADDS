#include <iostream>
#include <string>


int n(std::string str){
    // base case


    // else return str

    return 1;
}


void print(int n){
    if (n == 1) return ;

    std::cout << n << " ";
    print(n-1);
    std::cout << n << " ";

}


int main(int argc, char** argv){
    print(5);



    return 0;
}