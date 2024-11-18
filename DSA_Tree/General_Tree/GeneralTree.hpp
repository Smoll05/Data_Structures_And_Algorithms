#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

class GeneralTree : public Tree {
    Node* root;
    int size;

public:
    GeneralTree() : root(nullptr), size(0) {}

    Node* addRoot(int e) {
        if(root) throw logic_error("Root already exist");

        root = new Node();
        root->children = (Node**) malloc (10 * sizeof(Node*));
        root->val = e;
        size++;
        return root;
    }

    Node* addChild(Node* p, int e) {
        if(!p) throw logic_error("Node does not exist");
        if(p->num_child == 10) {
            p->num_child += 5;
            p->children = (Node**) realloc (p->children, p->num_child * sizeof(Node*));
        }

        Node* child = new Node();
        child->children = (Node**) malloc (10 * sizeof(Node*));
        child->val = e;
        child->parent = p;
        p->children[p->num_child++] = child;
        size++;
        return child;
    }

    Node* getRoot() {
        return root;
    }

    int getSize() {
        return size;
    }

    void remove(Node* n) {
        if(!n) throw logic_error("Node does not exist");
        if(n->num_child > 0) throw logic_error("Cannot remove " + to_string(n->val) + " because it has a children/child");

        if(n == root) {
            root = nullptr;
        } else {
            Node* parent = n->parent;
            for(int i = 0; i < parent->num_child; i++) {
                if(n == parent->children[i]) {
                    for(int j = i; j < parent->num_child - 1; j++) {
                        parent->children[j] = parent->children[j+1];
                    }
                    parent->num_child--;
                    break;
                }
            }
        }

        delete n;
        size--;
    }

    void preOrder(Node* p) {
        if(!p) return;

        cout << p->val << endl;
        for(int i = 0; i < p->num_child; i++) {
            preOrder(p->children[i]);
        }
    }

    void inOrder(Node* p) {
        if(!p) return;

        int mid = p->num_child / 2;
        for(int i = 0; i <= mid; i++) {
            inOrder(p->children[i]);
        }

        cout << p->val << endl;

        for(int i = mid + 1; i < p->num_child; i++) {
            inOrder(p->children[i]);
        }
    }

    void postOrder(Node* p) {
        if(!p) return;

        for(int i = 0; i < p->num_child; i++) {
            postOrder(p->children[i]);
        }
        cout << p->val << endl;
    }

    void bsfPrint(Node* p) {

    }
};