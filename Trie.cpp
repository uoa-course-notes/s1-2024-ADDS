#include "Trie.h"



Trie::Trie(){
    root = new Node();
}


void Trie::insert(std::string word){
    Node* node = root;
    for (char &c: word){
        std::string s(1, c);

        if(node -> children.find(s) == node -> children.end()){
            auto t = node -> children;
            std::pair<std::string, Node*> kp = {s, new Node};
            t.insert(kp);
            node -> children = t;
        }
        node = node -> children.find(s) -> second;
    }

    node -> isEndWord = true;
}


Node* Trie::navigate(std::string word, std::string& prefix, std::vector<std::string> parents){
    Node* node = root;
    for (char& c: word){
        std::string s(1,c);
        if (node -> children.find(s) == node -> children.end()){
            return node;
        }
        else{
            prefix += s;
            if (node -> children.find(s) -> second -> isEndWord) parents.push_back(prefix);
            node = node -> children.find(s) -> second;
        }
    }
    return node;
}



void Trie::dfs(Node* node, std::string prefix, std::vector<std::string>& result){
    if (node -> isEndWord) result.push_back(prefix);


    auto children = node -> children;
    for (auto itr = children.begin(); itr != children.end(); itr++){
        dfs(itr -> second, prefix + itr -> first, result);
    }
}
    
