#include "Node.hpp"
#include <iostream>
using namespace std;

class Tree {
    void print_Node(string prefix, Node* n) {
        cout << prefix;
        cout << "+-->: ";
        cout << n->val << endl;

        for (int i = 0; i < n->num_child; i++) {
            print_Node(prefix + "|   ", n->children[i]);
        }
    }

    bool check_parent(Node* curr, Node* par) {
        if (!curr) {
            return true;
        }

        if (curr->parent != par) {
            return false;
        }
        
        bool res = true;

        for (int i = 0; i < curr->num_child; i++) {
            res &= check_parent(curr->children[i], curr);
        }
        return res;
    }

public:
    virtual Node* addRoot(int) = 0;
    virtual Node* addChild(Node*, int) = 0;
    virtual void remove(Node*) = 0;
    virtual int getSize() = 0;
    virtual Node* getRoot() = 0;
    virtual void preOrder(Node*) = 0;
    virtual void inOrder(Node*) = 0;
    virtual void postOrder(Node*) = 0;
    virtual void bsfPrint(Node*) = 0;

    void print() {
        cout << "Size: " << getSize() << endl;

        if (!getRoot()) {
            cout << "EMPTY" << endl;
            return;
        }

        Node* curr = getRoot();
        print_Node("", getRoot());
        cout << "Status: " << check_parent(getRoot(), NULL) << endl;
    }
};