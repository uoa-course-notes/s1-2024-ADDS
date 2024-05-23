#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>


class Document{
    private:
        int identifier;
        int license_limit;
        std::string name;
    public:
        Document();
        Document(std::string name, int identifier, int license_limit);

        int getID();
        void setID(int id);

        int getLimit();
        void setLimit(int license_limit);

        std::string getName();
        void setName(std::string name);

};




#endif 