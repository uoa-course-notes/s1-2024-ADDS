#include "DocumentManager.h"
#include <cassert> // include the assert preprocessor micro, which is define din the cassert header file. 









int main(int argc, char** argv){
    // DocumentManager librarian;
    // Document d1("Guides", 1, 10);
    // Document d2("Intro to Algorithms", 4, 10);
    // Document d3("1982", 3, 1);
    // Document d4("Calculus", 2, 3);
    // Document d5("Contemporary Abstract Algebra", 10, 2);
    // Document d6("Intro_Recursive_Programming", 5, 3);

    // std::vector<Document> documents{d1, d2, d3, d4, d5, d6};

    // std::cout << "Librarian adding documents: " << std::endl;
    // for (int i=0; i<6; i++){
    //     librarian.addDocument(documents[i].getName(), 
    //                             documents[i].getID(), 
    //                  documents[i].getLimit());
    // }

    // std::cout << "Adding completed!" << std::endl;
    
    
    // ======================================================
    // ====================TESTING=========================== 
    // ======================================================
    
    // Searching 
    // Let's search for George Orwell's 1982 
    // std::string search_key = "1982";
    // int result = librarian.search(search_key);
    // if (result == d3.getID()) std::cout << "Yes" << std::endl;
    // else {
    //     std::cout << "No, insted of " <<d3.getID() <<  " we found " << result << std::endl;
    // }
    // the assert macro doesn't provide a parameter for a custom error messages. 
    // But we can add a description of the error using the comma operator. 
    // assert(librarian.search(d1.getName()) == d1.getID());
    // assert(librarian.search(d2.getName()) == d2.getID());
    // assert(librarian.search(d3.getName()) == d3.getID());
    // assert(librarian.search(d4.getName()) == d4.getID());
    // assert(librarian.search(d5.getName()) == d5.getID());
    // assert(librarian.search(d6.getName()) == d6.getID());
    // std::cout << "All search queries completed! My search function should be good to go!" << std::endl;


    // Borrowing documents. 
    // ===================================================
    // Firsly let's generate some sample patrons. 
    // Syntax: patroni = j where i and j are positive integers
    // i := part of the identifier
    // j := patronID of that particular patron 
    // int patron1 = 2;
    // int patron2 = 1;
    // int patron3 = 3;
    // int patron4 = 9;
    // int patron5 = 7;
    // int patron6 = 5;
    // int patron7 = 6;
    // int patron8 = 13;
    // std::vector<int> patrons{patron1, patron2,
    // patron3, patron4, patron5, patron6, patron7, patron8};

    // // Let 
    // for (int i=0; i<8; i++){
    //     librarian.addPatron(patrons[i]);
    // }

    // ===================================================
    // Test borrow procedure if a new patron were to borrow a book that is in the collection. 
    // int newPatron = 19;
    // int borrowingBook = 3;
    // assert(librarian.borrowDocument(borrowingBook, newPatron));

    // std::vector<int> Patrons = librarian.getListOfPatrons();
    // bool result = librarian.searchPatron(newPatron);
    // assert(result == true);
    // std::cout << "new patron has been registered" << std::endl;
    // printVector(Patrons);
    
    // Let's do that again, but with a book that is not in our current collection. 
    // int newPatron = 19;
    // int borrowingBook = 100;
    // assert(librarian.borrowDocument(borrowingBook, newPatron) == false);
    // std::cout << "Case 2 works" << std::endl;
    
    // Existing patron borrowing existing book 
    
    // assert(librarian.borrowDocument(d1.getID(),patron1) == true);
    // assert(librarian.borrowDocument(d2.getID(),patron2) == true);
    // assert(librarian.borrowDocument(d3.getID(),patron3) == true);
    // assert(librarian.borrowDocument(d4.getID(),patron4) == true);
    // assert(librarian.borrowDocument(d5.getID(),patron5) == true);
    // assert(librarian.borrowDocument(d6.getID(),patron6) == true);
    // std::cout << "Existing patron can borrow existing books!" << std::endl;
    // ===================================================
    

    // Existing patrons borrowing non-existent book 
    // assert(librarian.borrowDocument(100, 1) == false);
    // assert(librarian.borrowDocument(101, 2) == false);
    // assert(librarian.borrowDocument(102, 3) == false);
    // assert(librarian.borrowDocument(130, 13) == false);
    // assert(librarian.borrowDocument(140, 5) == false);
    // assert(librarian.borrowDocument(160, 6) == false);
    // std::cout << "Existing patron can indeed not borrow non-existing books!" << std::endl;


    // let's test the license limit of a particular book 
    // assert(librarian.borrowDocument(d3.getID(), patron1) == true);


    // I see ==========================problems (fixed)======================
    // assert(librarian.borrowDocument(d3.getID(), patron2) == false);
    // assert(librarian.borrowDocument(d3.getID(), patron3) == false);
    // assert(librarian.borrowDocument(d3.getID(), patron4) == false);

    // std::cout << d3.getName() << "'s limit has been reached. " << std::endl;
    // Let's check the borrower list 
//    librarian.displayBorrowers();

    // Let's test other document's license limit 


    // assert(librarian.borrowDocument(d4.getID(), patron1) == true);
    // assert(librarian.borrowDocument(d4.getID(), patron2) == true);
    // assert(librarian.borrowDocument(d4.getID(), patron3) == true);
    // assert(librarian.borrowDocument(d4.getID(), patron4) == false);
    // std::cout << d4.getName() << "'s limit has been reached. Currently already being borrowed by ";
    // librarian.displayBorrowers(); 

    // Sign up new patron 
    // int newPatron = 20;
    // librarian.borrowDocument(d5.getID(), newPatron);
    // librarian.borrowDocument(d5.getID(), 100);
    
    // librarian.displayPatrons();    
    // librarian.displayBorrowers(); 

    // librarian.returnDocument(d5.getID(), newPatron);
    // librarian.displayPatrons();    
    // librarian.displayBorrowers(); 

    // // std::cout << "======================In main===================";
    // // std::cin.ignore();

    // librarian.returnDocument(d5.getID(), 100);
    // librarian.displayPatrons();    
    // librarian.displayBorrowers(); 

    // from my observations, the list of patrons has removed the desired patrons
    // but the only trouble is getting the borrower list to also remove that specific borrowers who have returned the documents. 
    



    // Great! Gradescope accepts the two. Let's work on my last one. 

    // ===========================
    // Return documents
    // ===========================
    // Right, 3 patrons have borrowed document d4. 
    // Let's see what happens when one of them returns the document
    // They shouldn't appear in the borrower's list after that. 

    // librarian.returnDocument(d4.getID(), patron1);

    // // let's check the list of borrowers to see if patron1 has been removed. 
    // librarian.displayBorrowers();


    // std::cout << "Okay..." << std::endl;
    
    // std::cin.ignore();












    // std::unordered_map<int, std::vector<int>> borrowList = librarian.getListsOfBorrowers(); // stores the list of docID to patrons 

    // for (auto a: borrowList){
    //     std::cout << 
    // }

    // std::unordered_map<int, std::string> map;
    // std::pair<int, std::string> p1 = {1, "23"};
    // std::pair<int, std::string> p2 = {1, "231"};
    // std::pair<int, std::string> p3 = {1, "223"};
    // map.insert(p1);
    // map.insert(p2);
    // map.insert(p3);
    
    // // Instead we can map a vector values to one integer as follows:    
    // std::vector<int> values;
    // std::unordered_map<int, std::vector<int>> correctMap;
    
    // // Let's generate a random map 
    // // for (int i=1; i<10; i++){
    // //     correctMap.insert(std::pair<int, std::vector<int>>{i, std::vector{1, 2}});
    // // }
    // // actually let's not introduce too much bottleneck into my code 
    // correctMap.insert(std::pair{1, std::vector{2,23, 19, 19, 28, 48}});
    // correctMap.insert(std::pair{2, std::vector{1,29, 19, 10, 28, 48}});
    // correctMap.insert(std::pair{3, std::vector{2,39, 19, 190, 28, 48}});


        
    // for (auto element: correctMap){
    //     std::cout << "Key:" << element.first << " --> ";
    //     printVector(element.second);
    // }






    return 0;
}