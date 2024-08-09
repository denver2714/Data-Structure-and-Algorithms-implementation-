#include <iostream>
#include<queue>

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int value): value(value), left(nullptr), right(nullptr){}


};

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree(){
        root = nullptr;
    }


    bool insert(int value){
        Node *newNode = new Node(value);
        if(root == nullptr){root = newNode; return true;}
        Node* temp = root;
        while(true){
            if(newNode->value == temp->value) return false;
            if(newNode->value < temp->value){
                if(temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else{
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
//========================================================================
    void DFSPreOrder(Node* currentNode){
        std::cout << currentNode->value << " ";
        if(currentNode->left != nullptr){
            DFSPreOrder(currentNode->left);
        }
        if(currentNode->right != nullptr){
            DFSPreOrder(currentNode->right);
        }
    }
    void DFSPreOrder(){ DFSPreOrder(root); } // since root is private (overloaded function)
//==============================================================================
    void DFSPostOrder(Node* currentNode){
        
        if(currentNode->left != nullptr){
            DFSPreOrder(currentNode->left);
        }
        if(currentNode->right != nullptr){
            DFSPreOrder(currentNode->right);
        }
        std::cout << currentNode->value << " ";
    }
    void DFSPostOrder(){ DFSPostOrder(root); }
//====================================================================
    void DFSInOrder(Node* currentNode){
        
        if(currentNode->left != nullptr){
            DFSInOrder(currentNode->left);
        }
        std::cout << currentNode->value << " ";

        if(currentNode->right != nullptr){
            DFSInOrder(currentNode->right);
        }
        
    }
    void DFSInOrder(){ DFSInOrder(root); }
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


    myBST->DFSPreOrder();
    std::cout << "\n";
    myBST->DFSPostOrder();
    std::cout << "\n";
    myBST->DFSInOrder();
    return 0;
}