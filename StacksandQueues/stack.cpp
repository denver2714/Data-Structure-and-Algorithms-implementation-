#include <iostream>

struct Node {
    int value;
    Node* next;


    Node(int value): value(value), next(nullptr){}
};

class Stack {
private:
    Node* top;
    int height;
public:
    Stack(int value){
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack(){
        Node* temp = top;
        while (temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
        
    }

    void getTop() const {std::cout << "Top: " << top->value << std::endl;}
    void getHeight() const {std::cout << "Height: " << height << std::endl;}

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop(){
        if(height == 0) return INT_MIN;
        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;
        
        return poppedValue;
    }
};


int main(){
    Stack* myStack = new Stack(2);
    std::cout << myStack->pop() << "\n";
    std::cout << myStack->pop() << "\n";


    return 0;
}