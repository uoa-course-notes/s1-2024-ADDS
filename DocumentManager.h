#ifndef _DOCUMENT_MANAGER_H
#define _DOCUMENT_MANAGER_H
#include <iostream>
#include <unordered_map>
#include "Document.h"
#include <vector>
#include <algorithm>

class DocumentManager{
    private:
        std::unordered_map<int, Document*> Documents; // a collection of <docID:Document>
        std::vector<int> Patrons; // For this work, each patronID essentially represents a patron object even though a patron object is not needed in the implementation (though that would have also been good practice).
        std::unordered_map<int, std::vector<int>> borrowList; // stores the list of docID to patrons 

    public:
        void addDocument(std::string name, int id, int license_limit);

        void addPatron(int patronID);
        int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection 

        bool borrowDocument(int docid, int patronID);// returns true if the document is borrowed, 
        // false if it can not be borrowed (invalid patronID or the number of copies currently borrowed has reached the license limit)

        void returnDocument(int docid, int patronID);

        std::unordered_map<int, std::vector<int>> getListsOfBorrowers();

        std::vector<int> getListOfPatrons();

        bool searchPatron(int patronID);
        void displayBorrowers();
        void printVector(std::vector<int> S);

        ~DocumentManager();
};


/*
There's still bugs to be fixed! I am going to have a look at this tonight and debug this according to Gradescope input. 

*/



#endif 