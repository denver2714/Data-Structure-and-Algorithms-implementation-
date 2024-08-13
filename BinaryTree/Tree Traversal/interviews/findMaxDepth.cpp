/*
       1
      / \
     2   3
    /
   4

Question: Given a binary tree, write a function to calculate the maximum depth 
(or height) of the tree. The maximum depth is the number of nodes along the longest path from 
the root node down to the farthest leaf node.
*/


#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() {
        root = nullptr;
    }

    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) return false; // Doesn't allow duplicate values
            if (newNode->value < temp->value) { // If our new node is less than we put it to the left
                if (temp->left == nullptr) { // If the left child is a nullptr of the current node, then we put it there
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left; // Otherwise we move to the left
            } else { // If our new node is greater then we put it to the right
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }


    int maxDepth(Node* node) {
        if (node == nullptr) {
            return 0; // Base case: If the node is null, depth is 0
        }
        // Recursively get the depth of the left and right subtrees
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        // The depth of the current node is 1 + the maximum depth of its subtrees
        return 1 + std::max(leftDepth, rightDepth);
    }

    int getMaxDepth() {
        return maxDepth(root); // Start the depth calculation from the root
    }
};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    
    std::cout << "Maximum Depth of the Binary Search Tree: " << myBST->getMaxDepth() << "\n"; // Output the maximum depth

    return 0;
}
