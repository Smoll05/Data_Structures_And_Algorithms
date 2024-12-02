#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

class BinarySearchTree : public Tree {
    Node* root;
    int size;

public:
    BinarySearchTree() : root(nullptr), size(0) {}

    Node* addRoot(int e) {
        if(root) throw logic_error("Root already exist");

        root = new Node();
        root->val = e;
        size++;
        return root;
    }

    Node* addNode(int e) {
        if(!root) return addRoot(e);
        return addNodeHelper(root, e, nullptr);
    }

    Node* addNodeHelper(Node* p, int e, Node* parent) {
        if(!p) {
            Node* node = new Node();
            node->val = e;
            node->parent = parent;
            size++;
            return node;
        }

        if(e <= p->val) {
            p->left = addNodeHelper(p->left, e, p);
        } else {
            p->right = addNodeHelper(p->right, e, p);
        }

        return p;
    }

    Node* getRoot() {
        return root;
    }

    int getSize() {
        return size;
    }

    int remove(Node* n) {
        
    }

    void inorderHelper(Node* p) {
        if(!p) return;

        inorderHelper(p->left);
        cout << p->val << " ";
        inorderHelper(p->right);
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};