#include <iostream>

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr){}

};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree(){
        root = nullptr;
    }


    bool insert(int value){
        Node *newNode = new Node(value);
        if(root == nullptr){root = newNode; return true;}
        Node* temp = root;
        while(true){
            if(newNode->value == temp->value) return false; // Doesn't allow duplicate values
            if(newNode->value < temp->value){ // If our new node is less then we put to the left
                if(temp->left == nullptr){ //If the left child is a nullptr of the current node, then we put it there
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left; //Otherwise we move to the left
            }
            else{ // If our new node is greater then we put it to the right
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value){
        // if(root == nullptr) return false; // You dont actually need this
        Node* temp = root;
        while(temp){
            if(value < temp->value){temp = temp->left;}
            else if(value > temp->value){temp = temp->right;}
            else{return true;}
        }
        return false;
    }
};




int main(){
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);
       
    myBST->insert(27);
    std::cout << std::boolalpha;
    std::cout << "Contains 27: " << myBST->contains(27) << "\n";
    std::cout << "Contains 17: " << myBST->contains(17) << "\n";

    return 0;
}