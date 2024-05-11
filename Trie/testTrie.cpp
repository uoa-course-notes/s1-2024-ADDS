#include <cstring>
#include <iostream>

#define NUM_CHARS 256 //  just store ASCII strings 


struct trieNode{
    bool isEndOfWord; // is this a terminal node or is this a particular word? 
    trieNode* children[NUM_CHARS]; // look-up tables to not look at the list of children 
};




trieNode* createNode(){
    trieNode* newNode = new trieNode();
    for (int i=0; i < NUM_CHARS; i++){
        newNode -> children[i] = nullptr;
    }
    
    newNode -> isEndOfWord = false; // not at the end of word by default 
    return newNode;
};


bool trieInsert(trieNode** root, char* signedText){ // pass ** to not change by value 
    if (*root == nullptr){
        // Using a past by pointer. 
        *root = createNode();
    }

    // Don't want any negative indices in the look-up table 
    unsigned char* text = (unsigned char *)signedText;
    // use this traverse through our trie
    trieNode* tmp = *root;
    int length = strlen(signedText);

    for (int i=0; i< length; i++){
        if (tmp -> children[text[i]] == nullptr){
            // create a new node 
            tmp -> children[text[i]] = createNode();
        }

        tmp = tmp -> children[text[i]];
    }

    if (tmp -> isEndOfWord) return false;
    else{
        tmp -> isEndOfWord = true;
        return true;
    }


}

void printTrie_rec(trieNode* node, unsigned char* prefix, int length){
    unsigned char newPrefix[length + 2]; // space for one more symbol and the null character 
    memcpy(newPrefix, prefix, length);
    newPrefix[length + 1] = 0;

    // base case 
    if (node -> isEndOfWord){
        std::cout << "Word: " << prefix  << std::endl;
    }
    // there might be more children and so we need recurse further (which is not normally the case for recursive subroutine)
    for (int i = 0; i < NUM_CHARS; i++){
        if (node -> children[i] != nullptr){
            newPrefix[length] = i;
            printTrie_rec(node -> children[i], newPrefix, length + 1);
        }
    }
}



// Print out our trie 
void printTrie(trieNode* root){
    if (root == nullptr){
        std::cout << "Trie is empty." << std::endl;
        return ;
    }
    printTrie_rec(root, nullptr, 0);
}





int main(void){
    trieNode* root = nullptr;

    // When testing, we elaborately test the order of the insertion procedure. 
    trieInsert(&root, (char*)"KIT");
    trieInsert(&root, (char*)"CATTLE");
    trieInsert(&root, (char*)"KIN");
    trieInsert(&root, (char*)"CAT");
    trieInsert(&root, (char*)"HAPPY");

    printTrie(root);


    return 0;
}