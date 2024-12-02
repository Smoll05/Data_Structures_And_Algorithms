#include "Node.hpp"
#include <iostream>
using namespace std;

class Tree {
    void print_node(string prefix, Node* n, bool isLeft) {
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << n->val << endl;
        if (n->left) {
            print_node(prefix + "|   ", n->left, true);
        }
        if (n->right) {
            print_node(prefix + "|   ", n->right, false);
        }
    }

    bool check_parent(Node* curr, Node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent && par) {
                cout << "Illegal parent of " << curr->val << ": NULL -- must be " << par->val << endl;
            } else if (!par && curr->parent) {
                cout << "Illegal parent of " << curr->val << ": " << curr->parent->val << " -- must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->val << ": " << curr->parent->val << " -- must be " << par->val << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }

public:
    virtual Node* addRoot(int e) = 0;
    virtual Node* addNode(int e) = 0;
    virtual Node* getRoot() = 0;
    virtual int getSize() = 0;
    virtual int remove(Node* n) = 0;
    virtual void inorder() = 0;

    void print() {
        cout << "Size: " << getSize() << endl;
        if (!getRoot()) {
            cout << "EMPTY" << endl;
            return;
        }
        Node* curr = getRoot();
        print_node("", getRoot(), false);
        cout << "Status: " << check_parent(getRoot(), NULL) << endl;
    }
};