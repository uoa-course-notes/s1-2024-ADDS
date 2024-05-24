#include "DocumentManager.h"
#include "Document.h"
#include <unordered_map>


void DocumentManager::addDocument(std::string name,int id, int license_limit){
    /**
    @param
    id := docID (our key)
    @brief
    Document (our value)
    name and license_limit
    **/
    Documents.insert({id, new Document(name, id, license_limit)});
}



void DocumentManager::addPatron(int patronID){
    Patrons.push_back(patronID);
}


int DocumentManager::search(std::string name){ // returns docid if the name is in the collection of document.
    for (auto document: Documents){
        // check whether the provided name collides with any name in our collection of document 
        if (name == document.second->getName()) return document.second -> getID();
    }
    // By default, return 0 when the name is not in the collection 
    return 0;
}


bool DocumentManager::borrowDocument(int docid, int patronID){
    
    // let's check whether this is a new patron. 
    auto foundPatron = std::find(Patrons.begin(), Patrons.end(), patronID);
    if (foundPatron == Patrons.end()){
        // a new patron looking to borrow a document from the library '
        Patrons.push_back(patronID); // register the user as a patron with an ID 
    }

    // ======================================================================
    // Else, the patron has already borrowed document(s) in the past, 
    // hence, we don't need to append his/her id to the list of patron IDs.
    // ======================================================================


    // Check whether the document is even in the collection 
    // by checking whether docid exists in our current collection 
    bool foundDoc = false;
    for (auto doc: Documents){
        if (docid == doc.second -> getID()) foundDoc = true;
    }    
    if (foundDoc == false) return false;
    else{
        // document is found. Let's check whether the license limit of the document is within the range. 
        // Since we defined the borrowList as a map between key := docID and value := std::vector<int> patrons, to 
        // check whether a document's licenseLimit has not been breached, we just need to count the length of the patron vectors 
        if (borrowList[docid].size() >= Documents[docid]->getLimit()) return false;  // returns false 
        else{
            // Otherwise, the license limit hasn't been reached yet. Thus, we can let patron borrow the document 
            borrowList[docid].push_back(patronID);
            return true;
        }   
        // bad codes...     
    }
}


void DocumentManager::returnDocument(int docid, int patronID){
    // Not literally return document per sé but more of,
    // what happens when the patron returns the document? 

    // Then, we need to remove them from the document's list of patrons or borrowers 
    // However, to be pedantic, we want to make sure whether the patron even exists in the first place 
    std::vector<int>::iterator foundPatron = std::find(borrowList[docid].begin(), borrowList[docid].end(), patronID);

    if (foundPatron == borrowList[docid].end()) return; // stops the procedure immediately if the patron can't be found. 

    // otherwise, assist them in returning the document 
    else{
        borrowList[docid].erase(foundPatron); // remove the patron from the corresponding document key 
        Patrons.erase(foundPatron);
    }
}

std::unordered_map<int, std::vector<int>> DocumentManager::getListsOfBorrowers(){return borrowList;}


std::vector<int> DocumentManager::getListOfPatrons(){ return Patrons;}


bool DocumentManager::searchPatron(int patronID){
    for (auto a: Patrons){
        if (a == patronID) return true;
    }

    return false; // by default
}

void DocumentManager::displayBorrowers(){
    std::cout << "docID\t:<patronID>" << std::endl;
    
    for (auto b: borrowList){
        std::cout << b.first << "\t:";
        printVector(b.second);
    }
    std::cout << std::endl;
    
}


void DocumentManager::printVector(std::vector<int> S){
    std::cout << "<";
    for (int i = 0; i< S.size(); i++){
        if (i == S.size() -1) std::cout << S[i];
        else std::cout << S[i] << ",";
    }
    std::cout << ">" << std::endl;
}


DocumentManager::~DocumentManager(){
    for (auto element: Documents){
        delete element.second;
    }
}