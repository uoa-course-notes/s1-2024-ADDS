#include "DocumentManager.h"


void DocumentManager::addDocument(std::string name, int id, int license_limit){
       Document doc = {name, id, license_limit, 0};
        documents[id] = doc;
        name_to_id[name] = id;
}


void DocumentManager::addPatron(int patronID){
patrons.insert(patronID);
}


int DocumentManager::search(std::string name){
    auto it = name_to_id.find(name);
    if (it != name_to_id.end()) {
        return it->second;
    }
    return 0;
}


bool DocumentManager::borrowDocument(int docid, int patronID){
        if (patrons.find(patronID) == patrons.end() || documents.find(docid) == documents.end()) {
            return false;
        }

        Document& doc = documents[docid];
        if (doc.current_borrowed < doc.license_limit) {
            doc.current_borrowed++;
            borrowed_docs[patronID].insert(docid);
            document_borrowers[docid].insert(patronID);
            return true;
        }
        return false;

    return true;
}



void DocumentManager::returnDocument(int docid, int patronID){
    if (borrowed_docs.find(patronID) != borrowed_docs.end() &&
        borrowed_docs[patronID].find(docid) != borrowed_docs[patronID].end()) {
        borrowed_docs[patronID].erase(docid);
        document_borrowers[docid].erase(patronID);
        documents[docid].current_borrowed--;
    }

    
}



