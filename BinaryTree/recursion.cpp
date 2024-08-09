#include <iostream>

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




    bool rContains(Node* currentNode, int value){
        if(currentNode == nullptr) return false; // no nodes, root points to nullptr
        if(currentNode->value == value) return true;
        if(value < currentNode->value){
            return rContains(currentNode->left, value);
        }else{
            return rContains(currentNode->right, value);
        }
    }
    bool rContains(int value){ // Since root is private
        return rContains(root, value);
        }


        Node* deleteNode(Node* currentNode, int value){
            if(currentNode == nullptr) return nullptr;
            if(value < currentNode->value){
                currentNode->left = deleteNode(currentNode->left, value);
            }else if(value > currentNode->value){
                currentNode->right = deleteNode(currentNode->right, value);
            }else{
                if(currentNode->left == nullptr && currentNode->right == nullptr){ //deleting a leaf node
                    delete(currentNode);
                    return nullptr; // Because the previous node that was pointing to this node is still pointing to that same address
                }else if(currentNode->left == nullptr){
                    Node* temp = currentNode->right;
                    delete(currentNode);
                    return temp;
                }else if(currentNode->right == nullptr){ //with parent node from the right pointing to the left
                    Node* temp = currentNode->left;
                    delete(currentNode);
                    return temp;
                }else{
                    int subTreeMin = minValue(currentNode->right);
                    currentNode->value = subTreeMin;
                    currentNode->right = deleteNode(currentNode->right, subTreeMin);
                }
            }
            return currentNode;
        }

        void deleteNode(int value){
            root = deleteNode(root, value);
        } // Since root is private


        int minValue(Node*  currentNode){ //Find the minimum value [still work in progress]
            while(currentNode->left != nullptr){
                currentNode = currentNode->left;
            }
            return currentNode->value;
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
       

    std::cout << std::boolalpha;
    std::cout << "Contains 27: " << myBST->rContains(27) << "\n";
    std::cout << "Contains 17: " << myBST->rContains(17) << "\n";


    return 0;
}