#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int v): value(v), next(nullptr){}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int val) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    int getLength() const {
        return length;
    }
    
    Node* getIndex(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;    
    }

    bool setValue(int index, int value) {
        if (index < 0 || index >= length) return false;
        Node* temp = getIndex(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    void printList() {
        Node* newNode = head;
        while (newNode) {
            std::cout << newNode->value << "\n";
            newNode = newNode->next;
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

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void deleteLast() {
        if (length == 0) return;
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        Node* temp = head;
        Node* previous = nullptr;
        while (temp->next) {
            previous = temp;
            temp = temp->next;
        }
        tail = previous;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    void reverse(){
        Node* current = head;
        Node* previous = nullptr;
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




};

int main() {
    LinkedList* ll = new LinkedList(1);
    ll->append(2);
    ll->append(3);
    ll->append(4);
    ll->printList();

    std::cout << std::endl;
    ll->reverse();
    ll->printList();

    return 0;
}
