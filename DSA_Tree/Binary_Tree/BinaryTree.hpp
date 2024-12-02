#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

class BinaryTree : public Tree {
    Node* root;
    int size;

public:
    BinaryTree() : root(nullptr), size(0) {}

    Node* addRoot(int e) {
        if(root) throw logic_error("Root already exist");

        root = new Node();
        root->val = e;
        size++;
        return root;
    }

    Node* addLeft(Node* p, int e) {
        if(!p) throw logic_error("Parent does not exist");
        if(p->left) throw logic_error("Left child already exist");

        p->left = new Node();
        p->left->val = e;
        p->left->parent = p;
        size++;
        return p->left;
    }

    Node* addRight(Node* p, int e) {
        if(!p) throw logic_error("Parent does not exist");
        if(p->right) throw logic_error("Right child already exist");

        p->right = new Node();
        p->right->val = e;
        p->right->parent = p;
        size++;
        return p->right;
    }

    Node* getRoot() {
        return root;
    }

    int getSize() {
        return size;
    }

    int remove(Node* n) {
        if(!n) throw logic_error("Node does not exist");
        if(n->left && n->right) throw logic_error("Cannot remove " + to_string(n->val));

        int ret = n->val;
        Node* child = n->left ? n->left : n->right;

        if(n == root) {
            root = child;
            if(child) root->parent = nullptr;
        } else {
            if(n->parent->left == n) {
                n->parent->left = child;
            } else {
                n->parent->right = child;
            }
            if(child) child->parent = n->parent;
        }

        size--;
        free(n);
        return ret;
    }

    void attachSibling(Node* p, BinaryTree* t1) {
        if(!p -> parent) throw logic_error("Node does not have a parent");

        Node* parent = p->parent;
        if(parent->left == p) {
            if(parent->right) throw logic_error(to_string(p->val) + " already has sibling");

            parent->right = t1->getRoot();
            t1->getRoot()->parent = parent;
        } else {
            if(parent->left) throw logic_error(to_string(p->val) + " already has sibling");

            parent->left = t1->getRoot();
            t1->getRoot()->parent = parent;
        }
    }
};