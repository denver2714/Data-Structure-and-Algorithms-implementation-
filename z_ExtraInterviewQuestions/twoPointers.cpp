#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int value): value(value), next(nullptr), prev(nullptr){}
};


class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
    int length;
public:
    DoublyLinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList(){
        Node* temp = head;
        while(temp){
            std::cout << temp->value << "\n";
            temp = temp->next;
        }
    }


    void append(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void findingSum(int target){
        Node* first_ptr = head;
        Node* last_ptr = tail;


        if(head == tail) return;

        while(first_ptr != last_ptr){
        int refer = first_ptr->value + last_ptr->value;

            if(refer == target){
                std::cout << "Pair found: (" << first_ptr->value << ", " << last_ptr->value << ")" << "\n";
                return;
            }else if(refer > target){
                last_ptr = last_ptr->prev;
            }else if(target > refer){
                first_ptr = first_ptr->next;
            }
        }
    }


    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

};


    // 2 pointer algorithm, find the 2 numbers that add up to target
    // add first and last element
    // if the outcome is bigger than target, decrement the pointer to the right
    // if the target is bigger, we increment from the left

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    int target = 9;
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(5);
    myDLL->append(6);
    myDLL->append(9);
    myDLL->append(11);
    myDLL->append(12);
    myDLL->findingSum(target);

    return 0;
}
