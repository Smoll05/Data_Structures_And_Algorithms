#include <iostream>
#include "Node.hpp"

using namespace std;

class GeneralTree {
private:
    Node* root;

public:
    GeneralTree() {
        root = nullptr;
    }

    Node* addRoot(int num) {
        if(root) return nullptr;

        root = new Node();
        root->children = (Node**) malloc (5 * sizeof(Node*));
        root->num_child = 0;
        root->parent = nullptr;
        root->elem = num;
        return root;
    }

    Node* addChild(Node* p, int num) {
        if(!p) return nullptr;

        Node* child = new Node();
        child->parent = p;
        child->elem = num;
        child->num_child = 0;
        child->children = (Node**) malloc (5 * sizeof(Node*));

        p->children[p->num_child++] = child;
        return child;
    }

    void preorder(Node* p) {
        if(!p) return;

        cout << p->elem << endl;
        for(int i = 0; i < p->num_child; i++) {
            preorder(p->children[i]);
        }
    }
};