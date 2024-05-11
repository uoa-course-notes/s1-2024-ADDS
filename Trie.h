#ifndef TRIE_H
#define TRIE_H
#include "Node.h"

class Trie{
    private:
        Node* root;
    public:
        Trie();

        void insert(std::string word);
        Node* navigate(std::string word, std::string& prefix, std::vector<std::string> parents);
        void dfs(Node* node, std::string prefix, std::vector<std::string>& result);
};




#endif 