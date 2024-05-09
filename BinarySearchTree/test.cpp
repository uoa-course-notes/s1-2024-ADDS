#include "Node.h"
#include "BST.h"


void postOrderWalk(Node* rootNode){
    if (rootNode != nullptr){
        postOrderWalk(rootNode -> getLST());
        postOrderWalk(rootNode -> getRST());
        std::cout << rootNode -> getData() << " ";
    }
}

void preOrderWalk(Node* rootNode){

    if (rootNode != nullptr){
        std::cout << rootNode -> getData() << " ";
        preOrderWalk(rootNode -> getLST());
        preOrderWalk(rootNode -> getRST());
    }
}

void inOrderWalk(Node* rootNode){
    // Given a particular node N,
    // print all of its left children's values first, then
    // print the node's value itself, and finally
    // print all of its right children's values.

    // The other preOrder, and postOrder traversal are implemented similarly.
    if (rootNode != nullptr){
        inOrderWalk(rootNode -> getLST());
        std::cout << rootNode -> getData() << " ";
        inOrderWalk(rootNode -> getRST());
    }

    // Either the tree is empty or the particular subtree has been visited or walked. 
}



// Searching a BST


// Deleting a node from a BST



// Pedigree: shows the ancestors of a given node 


// Lineal chart: shows the decendants of a given node



// Displaying information about the tree
// Type of tree (property):
// Ordered? 
// Oriented? 
// Degree of each node 
// Branch (Non-terminal) nodes:
// Leaf (terminal) nodes: 
// level: 
// Height: 
// Depth: 
// Siblings and parents of each node: 



int main(int argc, char **argv){
    // node1 is basically the root node of the binary tree
    Node* root = nullptr;

    root = new Node(10);


    Node* node2 = new Node(-5);
    root -> setLST(node2);
    
    Node* node4 = new Node(-10);
    Node* node5 = new Node(-1);

    node2 -> setLST(node4);
    node2 -> setRST(node5);

    // Setting the 
    Node* node3 = new Node(41);
    root -> setRST(node3);


    node3 -> setLST(new Node(30));
    node3 -> setRST(new Node(45));
    node3 -> getRST() -> setRST(new Node(50));
    node3 -> getRST() -> getRST() -> setLST(new Node(70));

    // Our BST is created. 
    // Let's try to print them out inorderly. Left sub tree, data, and then right-subtree.

    std::cout << "In-order traversal: ";
    
    inOrderWalk(root);
    std::cout << std::endl;
    
    std::cout << "Pre-order traversal: ";
    preOrderWalk(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrderWalk(root);
    std::cout << std::endl;
    // EVERYTHING CHECKS OUT!!!

    /*
    Still to be implemenrted:
    BST using a dynamic array or vector.
    Given a list of values, build or populate the BST
    
    */






    return 0;
}