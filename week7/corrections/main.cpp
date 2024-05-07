#include <algorithm>
#include <iostream>


class Node{
    private:
        int data;
        Node* link;
    public:
        Node(int data, Node* link){
            this -> data = data; 
            this -> link = link;
        }
        Node(): Node(0, nullptr){}
    
        int getData(){return data;}
        Node* getLink(){return link;}

        void setData(int data){this -> data = data;}
        void setLink(Node* link){this -> link = link;}
        
};


class SLL{ // Remember that the list is 0-indexing origin 
    private:
        Node* head;
        int size;
        int* data;
    public:
        SLL(int* data, int size){
            if (size == 0) head = nullptr;
            else{
                head = nullptr;
                this -> size = size;
                this -> data = new int[size];
                for (int i=size-1; i>=0; i--){
                    Node* newNode = new Node(data[i], head);
                    head = newNode;
                }
            }
        }

        SLL():SLL({}, 0){}
        Node* getHead(){return head;}
        
        Node* getFront(){
            return getHead();
        }

        Node* MAXIMUM(){
            // Return the node pointer to the maximum element of the linked lis t
            Node* curr = head;
            if (isEmpty()) return nullptr;
            else{
                int max = 0;
                while (curr != nullptr){
                    if (curr -> getData() > max) max = curr -> getData();
                    curr = curr -> getLink();
                }
                return curr;
            }
        }
        Node* MINIMUM(){
            // Return the node pointer to the maximum element of the linked lis t
            Node* curr = head;
            if (isEmpty()) return nullptr;
            else{
                int min = 0;
                while (curr != nullptr){
                    if (curr -> getData() < min) min = curr -> getData();
                    curr = curr -> getLink();
                }
                return curr;
            }
        
        }

        void INSERT(int pos, int key){
            Node* curr = head;
            if (curr == nullptr) {
                if (pos == 0) pushFront(key);
                else if (pos == size-1) pushBack(key);
                return;
            }
            else {
                // non-empty list 
                if (size == 1){
                    head = new Node(key, curr -> getLink());
                }
                else{
                    Node* prevNode = findKthNode(pos-1);
                    Node* insertedNode = new Node(key, prevNode -> getLink());
                    prevNode -> setLink(insertedNode);
                }
                ++size;
                return;
            }
        }

        void pushFront(int key){
            head = new Node(key, head);
            ++size;
        }

        void pushBack(int key){
            Node* newLastNode = new Node(key, nullptr);
            Node* currLastNode = getBack();
            currLastNode -> setLink(newLastNode);
            size++;
        }

        Node* SUCCESSOR(){
            return nullptr;
        }

        Node* PREDECESSOR(){
            return nullptr;

        }


        Node* SEARCH(int key){
            Node* curr = head;
            if (curr == nullptr) return nullptr;
            else{
                // List contains at least one element 
                while (curr != nullptr){
                    if (curr -> getData() == key) break;
                    curr -> setLink(curr -> getLink());
                }
                return curr;
            }
        }


        Node* getBack(){
            return findKthNode(size-1);
        }

        void SORT(){

        }


        void reversedList(){}

        
        void printList(){
            Node* curr = head;
            if (isEmpty()) return;
            int i = 0;
            std::cout << "<";
            while (curr  != nullptr){
                if (i == size-1) std::cout << curr -> getData();
                else std::cout << curr -> getData() << ",";
                curr = curr -> getLink();
                i++;
            }
            std::cout << ">" << std::endl;   
        }
        Node* findKthNode(unsigned int k){ // k = destuination node
            Node* curr = head;
            // either the list is empty or the provided position 
            // is out of the list's scope, we return a nullptr.
            if (curr == nullptr && k+1 > size) return nullptr;
            int i = 0;
            while (curr != nullptr && i != k){
                curr = curr -> getLink();
                i++;
            }
            return curr;
        }

        void removeNode(unsigned int pos){
            if (pos == 0) removeFront();
            else if (pos == size-1) removeBack();
            else if (pos < 0 && pos > size-1){
                return; // invalid position, won't remove.
            }
            else{
                // now pos is between 0 and size -1 
                Node* prevNodeToBeDeleted = findKthNode(pos-1);
                Node* nodeTobeDeleted = findKthNode(pos);
                prevNodeToBeDeleted -> setLink(nodeTobeDeleted -> getLink());
                delete nodeTobeDeleted;
                nodeTobeDeleted = nullptr;
                --size;
            }
        }


        void removeFront(){
            Node* curr = head;
            head = head ->getLink();
            curr -> setLink(nullptr);
            delete curr;
            size--;
        }
       
        void removeBack(){
            Node* curr = head;
            if (curr == nullptr) return;
            else{
                // To handle the case when the only element is the head's 
                // that means, trying to find the node before it will result ina segementation fault error. 
                if (size == 1){
                    delete head;
                    head = nullptr;
                    return;
                }
                // List is non-empty 
                // Find the previous node of the node to be deleted (the last node in our case)
                Node* BeforeLastNode = findKthNode(size - 2);
                curr = BeforeLastNode -> getLink();
                BeforeLastNode -> setLink(nullptr);
                delete curr;                
                curr = nullptr;
                size--;
            }
            // std::cout << "last element deleted. Now at " << getSize() << std::endl;
        }
        

        bool isEmpty(){
            if (size == 0) return true;
            else return false;
        }
        
        unsigned int getSize(){
            return size;
        }

    


};





int main(void){
    int elements[] = {12, 4, 21,-13};
    int N = sizeof(elements)/sizeof(elements[0]);
    
    SLL list(elements, N);
    list.printList();
    // Node* last = list.getBack();
    // std::cout << last -> getData() << std::endl;
    // Node* target = list.findKthNode(4);
    // if (target == nullptr) std::cout << "The list is either empty or your provided index is greater than " << N << std::endl;
    // else std::cout << target -> getData() << std::endl; 
    // list.removeFront();
    // list.removeFront();


    // list.removeBack(); // 3
    // list.removeBack(); // 2
    // list.removeBack(); // 1
    // list.removeBack(); // 0
    
    // list.removeNode(N-1);
    list.pushBack(3893);
    std::cout << list.getSize() << std::endl;
    list.printList();
    // list.printList();


    return 0;
}