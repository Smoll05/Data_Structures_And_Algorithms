#include <iostream>
#include "Node.hpp"

class BinaryTree {
private:
    Node* root;
    int size;

public:
    BinaryTree() : root(nullptr), size(0) {}

    void insert(int num) {
        root = insertHelper(root, num);
    }

    Node* insertHelper(Node* root, int num) {
        if(!root) {
            root = new Node();
            root->val = num;
            size++;
            return root;
        }

        if(num <= root->val) {
            root->left = insertHelper(root->left, num);
        } else {
            root->right = insertHelper(root->right, num);
        }

        return root;
    }

    bool search(int num) {
        return searchHelper(root, num);
    }

    bool searchHelper(Node* root, int num) {
        if(!root) return false;

        if(root->val == num) return true;

        if(num <= root->val) return searchHelper(root->left, num);

        return searchHelper(root->right, num);
    }
};