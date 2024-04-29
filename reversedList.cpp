#include "LinkedList.h"







/* REVERSING A LINKED LIST Problem 
Given a linked list
List = [D_1|A_1, D_2|A_2, D_3|A_3, D_4|A_4, ... ,D_n-1|A_n-1, D_n|A_n = nullptr]
            |
           |
Head = [A_1]

The reversed state of the list should look like: 
Reversed_List = [D_1|A_1 = nullptr, D_2|A_2', D_3|A_3', D_4|A_4', ... ,D_n-1|A_n-1', D_n|A_n']
                                                                                        |
                                                                                        |
                                                                                Head = [A_n]



*/



int main(int argc, char** argv){
    int A[] = {23, 3, 9, -29, 34, 85,641};
    int n = sizeof(A)/sizeof(A[0]);
    LinkedList list(A, n);
    
    std::cout << "Before reversal: " << std::endl;
    
    list.printList();


    std::cout << "After reversal: " << std::endl;
    // list.reversed();
        
    // ===========================================================================
    Node* curr = list.getToFront();
    // std::cout << curr -> getData() << std::endl;
    
    // If the list is empty, return nullptr 

    // If it is not empty, check whether is has only one element, if so, then return the list 

    // If it is not empty and has more than one element, execute our main driver code. 

    // Change head pointer node to the last by looping through the list 

    









    // ===========================================================================


    list.printList();

    // Check whether the list has been reversed



    return 0;
}