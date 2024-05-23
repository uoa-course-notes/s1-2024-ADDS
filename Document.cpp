#include "Document.h"



Document::Document(){

}


Document::Document(std::string name, int identifier, int license_limit){
    this -> name = name;
    this -> identifier = identifier;
    this -> license_limit = license_limit;
}


int Document::getID(){return identifier;}


void Document::setID(int id){this -> identifier = id;};


int Document::getLimit(){return license_limit;}
void Document::setLimit(int license_limit){this -> license_limit = license_limit;}


std::string Document::getName(){return name;}
void Document::setName(std::string name){this -> name = name;}

