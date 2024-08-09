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



    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

//============================================================================
    //Interview Question!
    //Find the middle node of the linked list
    //Using the hare and tortoise algorithm

        Node* findMiddle() {
        if (length == 0) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main(){
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    std::cout << myLinkedList->findMiddle()->value;
    return 0;
}