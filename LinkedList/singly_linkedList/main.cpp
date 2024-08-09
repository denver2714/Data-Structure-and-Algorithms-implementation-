#include <iostream>

struct Node { 
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
}; 


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    Node *get(int index){
        if(index < 0 || index >= length) return nullptr;
        Node *temp = head;
        for(int i = 0; i < index; ++i){
            temp = temp->next;
        }
        return temp;
    }
    bool set(int index, int value){ //Set updates and existing node
        Node *temp = get(index); //from the 'get'
        if(temp){
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){ //adds a new node at a specified index
        if(index < 0 || index > length) return false;
        if(index == 0){
            prepend(value);
            return true;
        }
        if(index == length){
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1); // temp is behind the new node
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }


    void prepend(int value){
        Node * newNode = new Node(value);
        if (length == 0) {
            head == newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }



    void deleteLast() {
        if (length == 0) return; // if we have no nodes
        Node* temp = head;
        if (length == 1) { // if we have only one node
            head = nullptr;
            tail = nullptr;
        } else { //if we have 2 or more nodes
            Node* pre = head;
            while(temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;            
    }

    void deleteFirst(){
        if(length == 0) return;
        Node *temp = head;
        if(length == 1) {
            head = nullptr;
            tail = nullptr;
        } else{
            head = head->next;
            delete temp;
            length--;
        }

    }

    void deleteNode(int index){
        if(index < 0 || index >= length) return;
        if(index == 0) return deleteFirst();
        if(index == length - 1) return deleteLast();
        Node *prev = get(index - 1);
        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse(){
        //switch head and tail
        Node* temp = head;
        head = tail;
        tail = temp;
        //The after node
        Node* after = nullptr;
        //The before node
        Node* before = nullptr;
        for(int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before; //this rotates the node in reverse
            before = temp; //before now then moves to the node 
            temp = after;
        }
    }


    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);

    std::cout <<myLinkedList->get(2);

    return 0;
}
