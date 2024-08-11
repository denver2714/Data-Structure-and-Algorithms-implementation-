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
public:
    Node* root;
    BinarySearchTree(){
        root = nullptr;
    }


    Node* rInsert(Node* currentNode, int value){
        if(currentNode == nullptr) return new Node(value);
        if(value < currentNode->value){
            currentNode->left = rInsert(currentNode->left, value);
        }else if(value > currentNode->value){
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }

    bool insert(int value){
        if(root == nullptr) root = new Node(value);
        return rInsert(root, value); //since root is private
    }


    void BFS(){
        std::queue<Node*> myQueue;
        myQueue.push(root);
        
        while(myQueue.size() > 0){
            Node* currentNode = myQueue.front();
            myQueue.pop();
            std::cout << currentNode->value << " ";
            if(currentNode->left != nullptr){
                myQueue.push(currentNode->left);
            }
            if(currentNode->right != nullptr){
                myQueue.push(currentNode->right);
            }
        }
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

    myBST->BFS();

    return 0;
}