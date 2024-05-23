#ifndef _DOCUMENT_MANAGER_H
#define _DOCUMENT_MANAGER_H
#include <string>


class DocumentManager{
    private:



    public:
        void addDocument(std::string name,int license_limit);

        void addPatron(int patronID);
        int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection 

        bool borrowDocument(int docid, int patronID);// returns true if the document is borrowed, 
        // false if it can not be borrowed (invalid patronID or the number of copies currently borrowed has reached the license limit)

        void returnDocument(int docid, int patronID);

};




#endif 