#include "DocumentManager.h"

void printVector(std::vector<int> S){
    std::cout << "<";
    for (int i = 0; i< S.size(); i++){
        if (i == S.size() -1) std::cout << S[i];
        else std::cout << S[i] << ",";
    }
    std::cout << ">" << std::endl;;
}



int main(int argc, char** argv){
    DocumentManager librarian;
    Document d1("Guides", 1, 10);
    Document d2("Intro to Algorithms", 4, 10);
    Document d3("1982", 3, 1);

    std::vector<Document> documents{d1, d2, d3};

    std::cout << "Librarian adding documents: " << std::endl;
    for (int i=0; i<3; i++){
        librarian.addDocument(documents[i].getName(), 
                                documents[i].getID(), 
                     documents[i].getLimit());
    }

    std::cout << "Adding completed!" << std::endl;


    // Let's print out each document and its borrower. 
    
    std::unordered_map<int, std::vector<int>> borrowList = librarian.getListsOfBorrowers(); // stores the list of docID to patrons 

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