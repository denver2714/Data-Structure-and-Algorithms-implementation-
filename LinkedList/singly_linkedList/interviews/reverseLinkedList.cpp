
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

//============================================================================
    //Interview Question!
    //Reverse the Linked List
    //Using the 3 pointers!

    void reverseLinkedList(){
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head;

        while(current){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
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
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->reverseLinkedList();
    myLinkedList->printList();
    return 0;
}

