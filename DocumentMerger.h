#ifndef DOCUMENT_MERGER_H
#define DOCUMENT_MERGER_H
#include <string>


class DocumentMerger{
    private:

    public:
        void addDocument(std::string name, int id, int license_limit);
        void addPatron(int patronID);

        int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection 

        bool borrowDocument(int docid, int patronID); //returns true if document is borrowed
        // false, if it can not be borrowed (invalid patron id, or the number of copies currently borrowed has reached the license limit)


        void returnDocument(int docid, int patronID);
};



/*
Free to use any of the library containers or algorithms in the implementations, but I must make choices 
based on efficiency grounds. I can make reasonable assumptions around the relative freqeuncy of different operations. 
There are different ways I would choose to design this, but I should be able to justify my choice. 

*/







#endif 