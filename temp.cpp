#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value):left(nullptr), right(nullptr), value(value){}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree(): root(nullptr){}

    Node* insert(Node* currentNode, int value){
        if(currentNode == nullptr) {return new Node(value);}
        if(value < currentNode->value){
            currentNode->left = insert(currentNode->left, value);
        }
        else if(value > currentNode->value){
            currentNode->right = insert(currentNode->right, value);
        }
        return currentNode;
    }
};


int main(){

    BinaryTree* myBini = new BinaryTree();
    myBini->insert(myBini->root, 21);
    myBini->insert(myBini->root, 15);
    myBini->insert(myBini->root, 18);


    return 0;
}