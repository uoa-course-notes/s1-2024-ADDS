// #include "LinkedList.h"


// int main(int argc, char* *argv){
//     int A[] = {45, 20, 238, 10, 34, 9};
//     int N = sizeof(A)/sizeof(A[0]);
//     // create an array and populate the list 
//     LinkedList list(A, N);
//     // LinkedList list;
    
//     // std::cout << "Enter to continue\n";
//     // std::cin.ignore();
//     // Insert an element at a given position (works with both empty and non-empty list)
//     // =========================================

//     // int pos = 3;
//     // int data = 111;
//     // std::cout << "Before inserting " << data << " at " << pos << "\n";
//     // list.printList();
//     // list.insertPosition(pos, data);
//     // std::cout << "After inserting " << data << " at " << pos << "\n";
//     // list.printList();
    
//     // std::cout << "Insert more: \n";
//     // list.insertPosition(-1, 38);

//     // list.insertPosition(-10, 3902);
    
//     // list.insertPosition(10, 321);
//     // list.printList();

//     // =========================================




//     // =======================

//     // List traversal tests
//     // int pos = 0;
//     // Node* n = list.traverseTo(2);
//     // std::cout << n << std::endl;
//     // Node* n;
//     // for (pos = 1;pos <= N; pos++){
//     //     int pos_arg = pos-1;
//     //     n = list.traverseTo(pos_arg);
//     //     if (n == nullptr) break;
//     //     if (n -> getData() == A[pos_arg]){
//     //         std::cout << "Yes!\n";
//     //     }
//     //     else{
//     //         std::cout << "Uh oh" << std::endl;
//     //         std::cout << "Expect " << A[pos_arg] << " but got " << n -> getData() << " instead." << std::endl;
//     //         break;
//     //     }       
//     // }
//     // if (pos-1 != N){std::cout << "Something wrong! Pos = " << pos << " != N = " << N << std::endl;}
//     // else std::cout << "traversal works!!\n";
    
//     // =======================
    


    
   
//     // push front and push back (works with both empty and non empty lists)
//     // int data2 = 48;
//     // list.push_front(data2);
//     // list.printList();
//     // int data1 = 91;
//     // list.push_back(data1);
//     // list.printList();
    
//     // =======================

//     // Traversing without number of elements 
//     // Traverse to front of the list 
//     // Node* front = list.getToFront();
//     // if (front -> getData() == A[3]) std::cout << "get front is correctly implemented" << std::endl;
//     // else std::cout << "Something wrong with get front! " << front -> getData() << " != " << A[0] << std::endl;
    
//     // =======================

//     // =======================
//     // // Traverse to back of the list 
//     // Node* back = list.getToLast();
//     // if (back -> getData() == A[4]) std::cout << "get back is correctly implemented" << std::endl;
//     // else std::cout << "Something wrong with get last ==> " << back -> getData() << " != " << A[N-1] << std::endl;
//     // std::cout << "back's data = " << back -> getData() << " \n"
//     //           << "A[last] = " << A[4] << " \n"
//     //           << std::endl;
    
//     // =======================

//     // Delete elements from list


//     // delete from front 
//     // std::cout << "Before deleting from front:" << std::endl;
//     // list.printList();
//     // list.deleteFront();
//     // list.deleteFront();

//     // std::cout << "After deleting from front twice:" << std::endl;
//     // list.printList();



//     // ////////////////////////////////////////
//     // delete from back (some bugs on deleting from back)
//     // std::cout << "Before deleting from back:" << std::endl;
//     // list.printList();
    
//     // // list.deleteBack();
//     // // list.deleteBack();
//     // // if (d == true) std::cout << "Deleted successfully" << std::endl;
//     // // else std::cout << "Nope" << std::endl;
    
//     // std::cout << "After deleting from back:" << std::endl;
//     // list.printList();
//     // ////////////////////////////////////////





//     // std::cout << "Deleting at i-th position:\n";
//     // list.printList();
//     // int pos = N;
//     // bool del = list.deletePosition(pos);
//     // if (del == true) std::cout << "Position " << pos << " should be deleted by now\n";
//     // else std::cout << "Position is out of bound. Make sure pos >= 1 and <= size" << std::endl;
    
//     // list.printList();



//     // Test get or retrieval (works properly)
//     // int pos = 3;
//     // int data = list.get(pos);
//     // list.printList();
//     // std::cout << "At position " << pos << " lies " << data << std::endl;
    

//     // Test searching 
//     list.printList();
//     int t = 9;
//     std::cout << "Searching for target = " << t << " in list\n";
//     int index = list.search(t);
//     if (index == -1) std::cout << "Nowhere to be found" << std::endl;
//     else std::cout << t << " is found at position " << index << std::endl;  



//     return 0;
// }





