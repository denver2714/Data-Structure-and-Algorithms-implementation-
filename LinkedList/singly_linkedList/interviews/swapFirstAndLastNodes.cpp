
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
    //Swap the first and last Nodes

    void swapFandL() {
        // If the list is empty or has only one node, do nothing
        if (head == nullptr || head == tail) return;

        // If there are only two nodes
        if (head->next == tail) {
            tail->next = head; // Point the tail to the head
            head->next = nullptr; // Set the head's next to nullptr
            std::swap(head, tail); // Swap head and tail pointers
            return;
        }

        // General case: More than two nodes
        Node* current = head;
        // Traverse to the second last node
        while (current->next != tail) {
            current = current->next;
        }

        // Now current is the second last node
        current->next = head; // Link second last node to the first node
        tail->next = nullptr; // Set the last node's next to nullptr
        head = tail; // Update head to be the last node
        tail = current; // Update tail to be the second last node
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

    return 0;
}

