#include <iostream>
#include <queue>
#include "Node.hpp"

using namespace std;

class Tree {
private:
    Node* root;
    int size;

public:
    Tree() : root(nullptr), size(0) {}

    Node* addRoot(int num) {
        if(!root) {
            root = new Node(num);
            return root;
        }

        throw "Root Already Created";
    }

    Node* addLeft(Node* parent, int num) {
        if(parent && !parent->left) {
            parent->left = new Node(num);
            parent->left->parent = parent;
            size++;
            return parent->left;
        }

        throw "Parent is null or parent already has a left child";
    }

    Node* addRight(Node* parent, int num) {
        if(parent && !parent->right) {
            parent->right = new Node(num);
            parent->right->parent = parent;
            size++;
            return parent->right;
        }

        throw "Parent is null or parent already has a right child";
    }

    // int set(Node* parent, int num) {

    // }

    // Node* attach(Node* parent, Node* tree1, Node* tree2) {

    // }

    int remove(Node* parent) {
        if(parent->left && parent->right) {
            return -1;
        }

        Node* temp = parent;
        if(parent->left) {
            parent->left = parent;
        } else if(parent->right) {
            parent->right = parent;
        }

        int ret = temp->val;
        delete parent;
        return ret;
    }

    // Node* sibling(Node* parent) {

    // }

    void levelorder(Node* parent) {
        if(!parent) return;
        
        queue<Node*> queue;
        queue.push(parent);

        while(queue.size() != 0) {
            Node* curr = queue.front();
            cout << curr->val << endl;
            queue.pop();

            if(curr->left) queue.push(curr->left);
            if(curr->right) queue.push(curr->right);
        }
    }

    void preorder(Node* parent) {
        if(!parent) return;

        cout << parent->val << endl;
        preorder(parent->left);
        preorder(parent->right);
    }

    void inorder(Node* parent) {
        if(!parent) return;

        inorder(parent->left);
        cout << parent->val << endl;
        inorder(parent->right);
    }

    void postorder(Node* parent) {
        if(!parent) return;

        postorder(parent->left);
        postorder(parent->right);
        cout << parent->val << endl;
    }
};